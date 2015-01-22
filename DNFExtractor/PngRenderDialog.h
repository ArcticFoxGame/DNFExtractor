#pragma once

#include "Extractor.h"

// CPngRenderDialog �Ի���

class CPngRenderDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CPngRenderDialog)

public:
	int m_nIsRealPos;
	bool m_bIsLoadPng;
	CExtractor::NImgF_Index* m_pstPngIndex;

	CPngRenderDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CPngRenderDialog();

// �Ի�������
	enum { IDD = IDD_PNG_DIALOG };

protected:
	CStatic m_wndPngRender;

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	void ResizeRender();

	void Clear();
	void SetPngInfo(CExtractor::NImgF_Index* pstIndex);
	void Redraw();
};
