
// MFCAppSampleView.cpp : CMFCAppSampleView クラスの実装
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS は、プレビュー、縮小版、および検索フィルター ハンドラーを実装している ATL プロジェクトで定義でき、
// そのプロジェクトとのドキュメント コードの共有を可能にします。
#ifndef SHARED_HANDLERS
#include "MFCAppSample.h"
#endif

#include "MFCAppSampleDoc.h"
#include "MFCAppSampleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCAppSampleView

IMPLEMENT_DYNCREATE(CMFCAppSampleView, CView)

BEGIN_MESSAGE_MAP(CMFCAppSampleView, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCAppSampleView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CMFCAppSampleView コンストラクション/デストラクション

CMFCAppSampleView::CMFCAppSampleView() noexcept
{
	// TODO: 構築コードをここに追加します。

}

CMFCAppSampleView::~CMFCAppSampleView()
{
}

BOOL CMFCAppSampleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CMFCAppSampleView 描画

void CMFCAppSampleView::OnDraw(CDC* pDC)
{
	CMFCAppSampleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
	CPoint* p1;
	CPoint* p0 = pDoc->GetFirst();

	if (p0 == NULL)
		return;

	pDC->MoveTo(*p0);

	while (true)
	{
		p1 = pDoc->GetNext();

		if (p1 == NULL)
			return;

		pDC->LineTo(*p1);
		p0 = p1;
		pDC->MoveTo(*p0);
	}
}


// CMFCAppSampleView の印刷


void CMFCAppSampleView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCAppSampleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CMFCAppSampleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CMFCAppSampleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}

void CMFCAppSampleView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCAppSampleView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCAppSampleView の診断

#ifdef _DEBUG
void CMFCAppSampleView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCAppSampleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCAppSampleDoc* CMFCAppSampleView::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCAppSampleDoc)));
	return (CMFCAppSampleDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCAppSampleView メッセージ ハンドラー
