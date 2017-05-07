
// MFCTestDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CMFCTestDlg 对话框
class CMFCTestDlg : public CDialogEx
{
// 构造
public:
	CMFCTestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_MFCTEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CComboBox yearSmall;
	CComboBox monthSmall;
	CComboBox daySmall;
	CComboBox yearBig;
	CComboBox monthBig;
	CComboBox dayBig;

	afx_msg LRESULT OnSetSearchInfo(WPARAM wparam, LPARAM lparam);
	CComboBox sex;
	CComboBox merriage;
	CComboBox tallSmall;
	CComboBox tallBig;
	CComboBox house;
	CComboBox weightSmall;
	CComboBox weightBig;
	CComboBox education;
	CEdit salary;
};
