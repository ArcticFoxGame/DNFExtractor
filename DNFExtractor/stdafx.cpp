
// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// DNFExtractor.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

namespace custom
{
	BOOL isFolderExists(CString szPath)
	{
		DWORD attr;
		attr = GetFileAttributes(szPath);
		return (attr != (DWORD)(-1)) &&
			(attr & FILE_ATTRIBUTE_DIRECTORY);
	}

	BOOL CreateMuliteDirectory(CString szPath)
	{
		int len = szPath.GetLength();

		if (len < 2) return false;

		if ('\\' == szPath[len - 1] || '/' == szPath[len - 1])
		{
			szPath = szPath.Left(len - 1);
			len = szPath.GetLength();
		}

		if (len <= 0) return false;

		if (len <= 3)
		{
			if (isFolderExists(szPath))return true;
			else return false;
		}

		if (isFolderExists(szPath))return true;

		CString Parent;
		Parent = szPath.Left(szPath.ReverseFind('\\'));

		if (Parent.GetLength() <= 0)return false;

		BOOL Ret = CreateMuliteDirectory(Parent);

		if (Ret)
		{
			SECURITY_ATTRIBUTES sa;
			sa.nLength = sizeof(SECURITY_ATTRIBUTES);
			sa.lpSecurityDescriptor = NULL;
			sa.bInheritHandle = 0;
			Ret = (CreateDirectory(szPath, &sa) == TRUE);
			return Ret;
		}
		else
			return FALSE;
	}
}