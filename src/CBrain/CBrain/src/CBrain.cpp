#include "CBrain.h"
#include <windows.h>
#include <assert.h>

CBrain::CBrain(){
	ctrl[RUN] = false;
	ctrl[SUSPEND] = false;
	ctrl[END] = false;
	currentLevel = 0;
	emptyTask.SetEmpty();
	currentTask = &emptyTask;
	workThread = new thread(std::bind(&CBrain::ThreadWork, this));
	backThread = new thread(std::bind(&CBrain::ThreadBack, this));
}

void CBrain::push_back(CTask* task, int level){
	mutex.lock();
	//?�����ǰ��������ִ�в������ȼ����ڵ�ǰִ������������ͣ������
	if (level < currentLevel){
		SuspendRun();
	}
	mapTask[level].push_back(task);
	mutex.unlock();
}

void CBrain::Run(){
	ctrl[RUN] = true;
}

void CBrain::SuspendRun(){
	//?��ͣǰ̨����
	currentTask->SuspendRun();
	//?��ͣ
	ctrl[SUSPEND] = true;
	//?�����ȴ���ǰ����Ľڵ����
	while (ctrl[SUSPENDED] == false) Sleep(1);
}

void CBrain::RecoveryRun(){
	ctrl[SUSPEND] = false;
}

void CBrain::EndRun(){
	ctrl[END] = false;
}

void CBrain::ThreadWork(){
	while (ctrl[RUN] == false) Sleep(1);
	while (ctrl[END] == false){
		while (ctrl[SUSPEND] == true){
			ctrl[SUSPENDED] = true;
			Sleep(1);
		}
		ctrl[SUSPENDED] = false;
		Sleep(1);
		//?���Ȼ�ȡ���������񵽳�Ա����currentTask��
		GetCurrentTask();
		//?���������Ϳ�ʼִ��
		if (currentTask->isValid() == true){
			//?��ʼ������
			int intiResult = currentTask->initRun();
			//?�����1��ʾ��������
			if (intiResult == CTask::INITSUCCESS){
				//?�ѵ�ǰ����ĺ�̨�������б�
				AddBack(currentTask);
				int runResult = currentTask->Run();
				assert(runResult == CTask::RUNSUCCESS || runResult == CTask::RUNBACK || runResult == CTask::RUNSUSPEND);
				//?�������1��ʾҪɾ��ǰִ̨�кͺ�̨��⣬����0���ʾ��������ͣ�����ǳ��ں�̨������������
				if (runResult == CTask::RUNSUCCESS){
					DeleteTask(currentTask);
					DeleteBack(currentTask);
					delete currentTask;
				}
				//?����ǳ��ں�̨������Ҫ�Ѹ������ƶ���ͬ�����ȼ���ĩβ
				else if (runResult == CTask::RUNBACK) DeleteTask(currentTask);
				//?����Ǳ��ֶ���ͣ��ɾ����̨
				else if (runResult == CTask::RUNSUSPEND) DeleteBack(currentTask);
			}
			//?�����ʼ��ʧ�������������쳣���������Ҷ���������
			else{
				currentTask->ExceptionRun(intiResult);
				DeleteTask(currentTask);
				DeleteBack(currentTask);
				delete currentTask;
			}
		}
		else continue;
	}
}

void CBrain::ThreadBack(){
	while (ctrl[RUN] != true) Sleep(1);
	while (ctrl[END] != true){
		Sleep(1);
		mutex.lock();
		for (auto itlistTaskBack = listTaskBack.begin(); itlistTaskBack != listTaskBack.end(); itlistTaskBack++){
			if ((*itlistTaskBack)->ifExceptionRun == true){
				int exceptionResult = (*itlistTaskBack)->CheckException();
				if (exceptionResult != CTask::NOEXCEPTION){
					//?�����쳣֮������ͣ��ǰ����
					SuspendRun();
					(*itlistTaskBack)->ExceptionRun(exceptionResult);
					RecoveryRun();
				}
			}
		}
		mutex.unlock();
	}
}

void CBrain::DeleteTask(CTask* task){
	std::unique_lock<std::mutex> lock(mutex);
	for (auto itmapTask = mapTask.begin(); itmapTask != mapTask.end(); itmapTask++){
		for (auto itlist = itmapTask->second.begin(); itlist != itmapTask->second.end(); itlist++){
			//?���������ͬ��task
			if ((*itlist)->uuid == task->uuid){
				//?�������0����������ڵ���˵������
				assert(itmapTask->second.size() != 0);
				//?����������ֻ��һ��������ôֱ���Ƴ�һ����map�ڵ�
				if (itmapTask->second.size() == 1) mapTask.erase(itmapTask);
				//?����ж��������ô�Ƴ�һ��
				else itmapTask->second.erase(itlist);
				return;
			}
		}
	}
}

void CBrain::DeleteBack(CTask* task){
	std::unique_lock<std::mutex> lock(mutex);
	for (auto itlistTaskBack = listTaskBack.begin(); itlistTaskBack != listTaskBack.end(); itlistTaskBack++){
		if ((*itlistTaskBack)->uuid == task->uuid){
			listTaskBack.erase(itlistTaskBack);
			break;
		}
	}
}

void CBrain::GetCurrentTask(){
	std::unique_lock<std::mutex> lock(mutex);
	//?ȡ�������������ȼ����������ǰ������
	for (auto itmapTask = mapTask.begin(); itmapTask != mapTask.end(); itmapTask++){
		currentLevel = itmapTask->first;
		currentTask = itmapTask->second.front();
		return;
	}
	currentTask = &emptyTask;
}

void CBrain::AddBack(CTask* task){
	std::unique_lock<std::mutex> lock(mutex);
	listTaskBack.push_back(currentTask);
}

void CBrain::MoveToEnd(CTask* task){
	std::unique_lock<std::mutex> lock(mutex);
	for (auto itmapTask = mapTask.begin(); itmapTask != mapTask.end(); itmapTask++){
		for (auto itlist = itmapTask->second.begin(); itlist != itmapTask->second.end(); itlist++){
			if (task->uuid == (*itlist)->uuid){
				itmapTask->second.erase(itlist);
				itmapTask->second.push_back(task);
				return;
			}
		}
	}
}

int main(){
	return 0;
}