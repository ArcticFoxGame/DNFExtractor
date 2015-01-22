
// DNFExtractorDlg.h : ͷ�ļ�
//

#pragma once

#include "Extractor.h"
#include "ImgListCtrl.h"
#include "PngListCtrl.h"
#include "PngRenderDialog.h"

// CDNFExtractorDlg �Ի���
class CDNFExtractorDlg : public CDialogEx
{
// ����
public:
	CDNFExtractorDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void UpdatePngList();
	void UpdatePngRender(int nPos);
	char* GetActiveImgName();

// �Ի�������
	enum { IDD = IDD_DNFEXTRACTOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	bool m_bIsLoadPng;
	bool m_bIsRealPos;

	HICON m_hIcon;
	HBITMAP m_hPngBitmap;
	CString m_szFilename;
	CString m_szSearchTxt;
	CImgListCtrl m_wndImgList;
	CPngListCtrl m_wndPngList;
	CPngRenderDialog m_wndPngRender;
	CButton m_wndOpenBtn;
	CButton m_wndCloseBtn;
	CButton m_wndSearchClrBtn;
	CExtractor* m_poExtractor;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CExtractor* GetExtractor() const { return m_poExtractor; }

	afx_msg void OnEnChangeFilenameEdit();
	afx_msg void OnBnClickedSearchClear();
	afx_msg void OnEnChangeSearchEdit();
	afx_msg void OnBnClickedOpenFile();
	afx_msg void OnBnClickedCloseFile();
	afx_msg void OnLvnItemchangedImgList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedPngList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedTrueposCheck();
	afx_msg void OnBnClickedRealposCheck();
};
