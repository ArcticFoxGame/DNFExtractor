#pragma once

#ifndef _EXTRACTOR_H_
#define _EXTRACTOR_H_

#include "stdafx.h"
#include <vector>
#include "zlib/zlib.h"
#pragma comment(lib, "zlib.lib")
#include "libpng/png.h"
#pragma comment(lib, "libpng15.lib")

#define MAX_FILENAME_LENGTH 256
#define MAX_HEADER_FLAG 16

#define ARGB_1555 0x0e
#define ARGB_4444 0x0f
#define ARGB_8888 0x10
#define ARGB_LINK 0x11

#define COMPRESS_ZLIB 0x06
#define COMPRESS_NONE 0x05

class CExtractor
{
public:
	struct NPK_Header
	{
		char flag[MAX_HEADER_FLAG]; // �ļ���ʶ "NeoplePack_Bill"
		int count;     // �����ļ�����Ŀ
	};

	struct NPK_Index
	{
		unsigned int offset;  // �ļ��İ���ƫ����
		unsigned int size;    // �ļ��Ĵ�С
		char name[MAX_FILENAME_LENGTH];// �ļ���
	};


	struct NImgF_Header
	{
		char flag[MAX_HEADER_FLAG]; // �ļ���ʯ"Neople Img File"
		int index_size;	// �������С�����ֽ�Ϊ��λ
		int unknown1;
		int unknown2;
		int index_count;// ��������Ŀ
	};

	struct NPngF_Type
	{
		unsigned int dwType; //Ŀǰ��֪�������� 0x0E(1555��ʽ) 0x0F(4444��ʽ) 0x10(8888��ʽ) 0x11(�������κ����ݣ�������ָ����ͬ��һ֡)
		unsigned int dwCompress; // Ŀǰ��֪�������� 0x06(zlibѹ��) 0x05(δѹ��)
	};

	struct NPngF_Info
	{
		int width;        // ���
		int height;       // �߶�
		int size;         // ѹ��ʱsizeΪѹ�����С��δѹ��ʱsizeΪת����8888��ʽʱռ�õ��ڴ��С
		int key_x;        // X�ؼ��㣬��ǰͼƬ����ͼ�е�X����
		int key_y;        // Y�ؼ��㣬��ǰͼƬ����ͼ�е�Y����
		int max_width;    // ��ͼ�Ŀ��
		int max_height;   // ��ͼ�ĸ߶ȣ��д�������Ϊ�˶��뾫��
	};

	struct NImgF_Index
	{
		unsigned int m_dwIsLink;
		unsigned long m_dwBufferSize;
		BYTE* m_pData;
		NPngF_Type m_stType;
		NPngF_Info m_stHeader;

		NImgF_Index()
		{
			m_dwIsLink = 0;
			m_dwBufferSize = 0;
			m_pData = NULL;
			memset(&m_stType, 0, sizeof(m_stType));
			memset(&m_stHeader, 0, sizeof(m_stHeader));
		}

		~NImgF_Index()
		{
			if (m_pData != NULL && m_dwIsLink == FALSE)
			{
				delete[] m_pData;
			}
			m_pData = NULL;
			m_dwIsLink = 0;
			m_dwBufferSize = 0;
			memset(&m_stType, 0, sizeof(m_stType));
			memset(&m_stHeader, 0, sizeof(m_stHeader));
		}
	};

	struct WriteInfo
	{
		BYTE* pBuffer;
		UINT dwMaxSize;
		UINT dwSize;
	};

	static char s_szFileNameFlag[MAX_FILENAME_LENGTH];
	static char s_szHeaderFlag[MAX_HEADER_FLAG];
	static char s_szImgFlag[MAX_HEADER_FLAG];
	static const UINT s_dwBufferSize = 1024 * 1024 * 3;

	CExtractor(CString szFileName);
	virtual ~CExtractor();

	bool IsLoad() const { return m_bIsLoad; }
	int GetImgCount() const { return m_vIndex.size(); }
	NPK_Index* GetImgByPos(int nPos);

	void SetActiveImg(int nPos);
	void LoadImgData(UINT dwOffset);

	int GetPngCount() const { return m_vPngIndex.size(); }
	NImgF_Index* GetPngByPos(int nPos);

	int NpkToPng(void* pDestBuff, UINT& dwDestSize, const BYTE* pSrcBuff, UINT dwSrcBuff, int nWidth, int nHeight, int nType, int x = 0, int y = 0, int nDestWidth = 0, int nDestHeight = 0);
	static void pngWriteCallback(png_structp png_ptr, png_bytep data, png_size_t length);
	static void pngWriteFlush(png_structp png_ptr);

	HRESULT LoadImageFromBuffer(void* pBuffer, int nSize, CImage& img);

private:
	bool		m_bIsLoad;
	CFile		m_oFile;
	CString		m_szFilename;
	//NPK_Header	m_stHeader;
	NImgF_Header m_stActiveImgHeader;
	std::vector<NPK_Index>	m_vIndex;
	std::vector<NImgF_Index> m_vPngIndex;
};

#endif // _EXTRACTOR_H_