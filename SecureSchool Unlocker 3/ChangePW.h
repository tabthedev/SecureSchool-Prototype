#pragma once
#include "afxdialogex.h"


// ChangePW 대화 상자

static CString userWrittenPassword_;

static void changeUWP(CString a) {
	userWrittenPassword_ = a;
}

class ChangePW : public CDialogEx
{
	DECLARE_DYNAMIC(ChangePW)
public:
	ChangePW(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	//virtual ~ChangePW();
	CString NEW_PW;

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SECURESCHOOL_CHANGEPW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonChange();
	//afx_msg void setStaticThingy();
};
