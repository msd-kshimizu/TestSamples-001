
// MFCAppSampleDoc.h : CMFCAppSampleDoc クラスのインターフェイス
//


#pragma once


class CMFCAppSampleDoc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CMFCAppSampleDoc() noexcept;
	DECLARE_DYNCREATE(CMFCAppSampleDoc)

// 属性
public:
	INT		m_nPoints;		// 点の数
	CSize	m_sizeDoc;		// 最大サイズ
	INT		m_getptr;		// 次の点（番号）
	CPoint	m_points[1024];	// 図形の点

// 操作
public:
	CPoint	*GetNext();		// 次の点を取得
	CPoint	*GetFirst();	// 最初の点を取得

// オーバーライド
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 実装
public:
	virtual ~CMFCAppSampleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 検索ハンドラーの検索コンテンツを設定するヘルパー関数
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
