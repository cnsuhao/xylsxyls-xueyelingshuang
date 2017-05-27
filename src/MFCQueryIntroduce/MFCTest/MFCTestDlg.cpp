
// MFCTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCTest.h"
#include "MFCTestDlg.h"
#include "afxdialogex.h"
#include "resource.h"
#include "Manager.h"
#include "Person.h"
#include "Search.h"
#include "CStringManager/CStringManagerAPI.h"
#include "ConfigInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCTestDlg 对话框



CMFCTestDlg::CMFCTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMFCTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, yearSmall);
	DDX_Control(pDX, IDC_COMBO2, monthSmall);
	DDX_Control(pDX, IDC_COMBO3, daySmall);
	DDX_Control(pDX, IDC_COMBO4, yearBig);
	DDX_Control(pDX, IDC_COMBO5, monthBig);
	DDX_Control(pDX, IDC_COMBO6, dayBig);
	DDX_Control(pDX, IDC_COMBO7, sex);
	DDX_Control(pDX, IDC_COMBO13, merriage);
	DDX_Control(pDX, IDC_COMBO8, tallSmall);
	DDX_Control(pDX, IDC_COMBO9, tallBig);
	DDX_Control(pDX, IDC_COMBO14, house);
	DDX_Control(pDX, IDC_COMBO10, weightSmall);
	DDX_Control(pDX, IDC_COMBO11, weightBig);
	DDX_Control(pDX, IDC_COMBO12, education);
	DDX_Control(pDX, IDC_EDIT1, salary);
}

BEGIN_MESSAGE_MAP(CMFCTestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCTestDlg::OnBnClickedButton1)
    ON_MESSAGE(GetConfig(FillSearchInt, int), &CMFCTestDlg::OnSetSearchInfo)
END_MESSAGE_MAP()


// CMFCTestDlg 消息处理程序

BOOL CMFCTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCTestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCTestDlg::OnBnClickedButton1()
{
	//::SendMessage(GetDlgItem(IDC_STATIC1)->m_hWnd, WM_SETTEXT, 0, (LPARAM)"shit");
	// TODO: 在此添加控件通知处理程序代码

	Search search;
	Manager::SearchInfo(m_hWnd, &search);
	vector<Person> vecPerson = Manager::Find(search);
	AfxMessageBox(CStringManager::Format("一共找到%d张",vecPerson.size()).c_str());
	Manager::ShowDlg(vecPerson);
}

LRESULT CMFCTestDlg::OnSetSearchInfo(WPARAM wparam, LPARAM lparam){
	Search* search = (Search*)lparam;
	CString strYearSmall;
	yearSmall.GetWindowTextA(strYearSmall);
	CString strMonthSmall;
	monthSmall.GetWindowTextA(strMonthSmall);
	CString strDaySmall;
	daySmall.GetWindowTextA(strDaySmall);
	search->smallBirth = IntDateTime(atoi(CStringManager::Format("%d%02d%02d", atoi(strYearSmall), atoi(strMonthSmall), atoi(strDaySmall)).c_str()), 0);

	CString strYearBig;
	yearBig.GetWindowTextA(strYearBig);
	CString strMonthBig;
	monthBig, GetWindowTextA(strMonthBig);
	CString strDayBig;
	dayBig.GetWindowTextA(strDayBig);
	search->bigBirth = IntDateTime(atoi(CStringManager::Format("%d%02d%02d", atoi(strYearBig), atoi(strMonthBig), atoi(strDayBig)).c_str()), 0);

	CString strSex;
	sex.GetWindowTextA(strSex);
	search->sex = (LPSTR)(LPCTSTR)strSex;

	CString strMerriage;
	merriage.GetWindowTextA(strMerriage);
	search->marriage = (LPSTR)(LPCTSTR)strMerriage;

	CString strTallSmall;
	tallSmall.GetWindowTextA(strTallSmall);
	search->smallTall = atoi(strTallSmall);

	CString strTallBig;
	tallBig.GetWindowTextA(strTallBig);
	search->bigTall = atoi(strTallBig);

	CString strHouse;
	house.GetWindowTextA(strHouse);
	search->house = (LPSTR)(LPCTSTR)strHouse;

	CString strWeightSmall;
	weightSmall.GetWindowTextA(strWeightSmall);
	search->smallWeight = atoi(strWeightSmall);

	CString strWeightBig;
	weightBig.GetWindowTextA(strWeightBig);
	search->bigWeight = atoi(strWeightBig);

	CString strEducation;
	education.GetWindowTextA(strEducation);
	search->education = (LPSTR)(LPCTSTR)strEducation;

	CString strSalary;
	salary.GetWindowTextA(strSalary);
	search->salary = atoi(strSalary);
	return 0;
}