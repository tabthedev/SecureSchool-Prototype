#pragma once
#include "afxdialogex.h"

#define _CRT_SECURE_NO_WARNINGS


// ConfirmNewPW 대화 상자

class ConfirmNewPW : public CDialogEx
{
	DECLARE_DYNAMIC(ConfirmNewPW)
public:
	ConfirmNewPW(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~ConfirmNewPW();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SECURESCHOOL_CONFIRMPW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CEdit EnterNewPasswordHereDeveloper;
	afx_msg void OnBnClickedConfirmNewpw();
	afx_msg void OnEnChangeCheckerNewpw();
	CStatic static_newpw_FinalCheck;
	afx_msg void OnStnClickedStaticFinal();
	CString m_static_newpw_fc;
};
