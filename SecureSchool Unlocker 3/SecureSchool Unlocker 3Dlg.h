
#pragma once
#define WM_TRAYICON_MSG WM_USER + 1


// CSecureSchoolUnlocker3Dlg 대화 상자

class CSecureSchoolUnlocker3Dlg : public CDialogEx
{
	// 생성입니다.
public:
	CSecureSchoolUnlocker3Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SECURESCHOOL_UNLOCKER_3_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


	// 구현입니다.
protected:
	HICON m_hIcon;

	LRESULT TrayIconMessage(WPARAM wParam, LPARAM lParam);

	bool m_bTrayStatus;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	// // 비번 입력임
	CString PWInputR;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedCancelButton();
	void TraySetting(void);
	void InitTray(void);
};
