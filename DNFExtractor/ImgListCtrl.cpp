// ImgListCtrl.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DNFExtractor.h"
#include "ImgListCtrl.h"


// CImgListCtrl

IMPLEMENT_DYNAMIC(CImgListCtrl, CListCtrl)

CImgListCtrl::CImgListCtrl()
{

}

CImgListCtrl::~CImgListCtrl()
{
}


BEGIN_MESSAGE_MAP(CImgListCtrl, CListCtrl)
	ON_WM_CREATE()
END_MESSAGE_MAP()



// CImgListCtrl ��Ϣ�������




int CImgListCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CListCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������

	return 0;
}
