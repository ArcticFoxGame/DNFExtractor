
// DNFExtractorDlg.h : ͷ�ļ�
//

#pragma once

#include "Extractor.h"

// CDNFExtractorDlg �Ի���
class CDNFExtractorDlg : public CDialogEx
{
// ����
public:
	CDNFExtractorDlg(CWnd* pParent = NULL);	// ��׼���캯��
	void UpdatePngList();
	void UpdatePngRender(int nPos);

// �Ի�������
	enum { IDD = IDD_DNFEXTRACTOR_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;
	HBITMAP m_hPngBitmap;
	bool m_bIsLoadPng;
	CString m_szFilename;
	CString m_szSearchTxt;
	CListCtrl* m_wndImgList;
	CListCtrl* m_wndPngList;
	CButton* m_wndOpenBtn;
	CButton* m_wndCloseBtn;
	CButton* m_wndSearchClrBtn;
	CExtractor* m_poExtractor;
	CExtractor::NImgF_Index* m_pstPngIndex;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeFilenameEdit();
	afx_msg void OnBnClickedSearchClear();
	afx_msg void OnEnChangeSearchEdit();
	afx_msg void OnBnClickedOpenFile();
	afx_msg void OnBnClickedCloseFile();
	afx_msg void OnLvnItemchangedImgList(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnLvnItemchangedPngList(NMHDR *pNMHDR, LRESULT *pResult);
};
