
// MFCAppSampleDoc.cpp : CMFCAppSampleDoc クラスの実装
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "MFCAppSample.h"
#endif

#include "MFCAppSampleDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMFCAppSampleDoc

IMPLEMENT_DYNCREATE(CMFCAppSampleDoc, CDocument)

BEGIN_MESSAGE_MAP(CMFCAppSampleDoc, CDocument)
END_MESSAGE_MAP()


// CMFCAppSampleDoc コンストラクション/デストラクション

CMFCAppSampleDoc::CMFCAppSampleDoc() noexcept
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CMFCAppSampleDoc::~CMFCAppSampleDoc()
{
}

BOOL CMFCAppSampleDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。
	m_nPoints = 0;
	m_sizeDoc = CSize(800, 600);

	return TRUE;
}




// CMFCAppSampleDoc のシリアル化

void CMFCAppSampleDoc::Serialize(CArchive& ar)
{
	int i;

	if (ar.IsStoring())
	{
		// TODO: 格納するコードをここに追加してください。
		ar << m_nPoints;

		for (i = 0; i < m_nPoints; i++)
		{
			ar << m_points[i];
		}
	}
	else
	{
		// TODO: 読み込むコードをここに追加してください。
		ar >> m_nPoints;

		for (i = 0; i < m_nPoints; i++)
		{
			ar >> m_points[i];
		}
	}
}

// 最初の描画点を取得
CPoint* CMFCAppSampleDoc::GetFirst()
{
	if (m_nPoints == 0)
		return NULL;

	m_getptr = 0;
	return &m_points[0];
}

// 次の描画点を取得
CPoint* CMFCAppSampleDoc::GetNext()
{
	m_getptr++;

	if (m_getptr >= m_nPoints)
		return NULL;

	return &m_points[m_getptr];
}

#ifdef SHARED_HANDLERS

//縮小版のサポート
void CMFCAppSampleDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// このコードを変更してドキュメントのデータを描画します
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 検索ハンドラーのサポート
void CMFCAppSampleDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ドキュメントのデータから検索コンテンツを設定します。
	// コンテンツの各部分は ";" で区切る必要があります

	// 例:      strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CMFCAppSampleDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CMFCAppSampleDoc の診断

#ifdef _DEBUG
void CMFCAppSampleDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMFCAppSampleDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CMFCAppSampleDoc コマンド
