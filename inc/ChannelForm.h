
#ifndef _CHANNELFORM_H_
#define _CHANNELFORM_H_

#include <FBase.h>
#include <FUi.h>
#include  <FApp.h>
#include <FNet.h>
using namespace Tizen::Net::Http;
using namespace Tizen::Base;


class ChannelForm :
	public Tizen::Ui::Controls::Form,
	public Tizen::Ui::IActionEventListener,
	public Tizen::Ui::Scenes::ISceneEventListener,
	public Tizen::Ui::Controls::IListViewItemEventListener,
	public Tizen::Ui::Controls::IListViewItemProvider,
 	public Tizen::Ui::IKeyEventListener,
 	public Tizen::Ui::Controls::IFormBackEventListener,
 	public Tizen::Net::Http::IHttpTransactionEventListener
{

// Construction
public:
	ChannelForm(void);
	virtual ~ChannelForm(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);
//	void requestHttpGet(String url, String args, Object * userObjects);


// Implementation
protected:
private :
	HttpSession * mHttpSession;
	void requestHttpGet(String url);
	Tizen::Ui::Controls::ListView* __pListView;
	Tizen::Ui::Controls::ListContextItem* __pItemContext;
	Tizen::Graphics::Bitmap* __pLogo;
	Tizen::App::AppResource* pAppResource;
	  static const int ID_FORMAT_BITMAP = 101;


// Generated call-back functions
public:
	virtual void OnActionPerformed(const Tizen::Ui::Control& source,
			int actionId);
	virtual void OnSceneActivatedN(
			const Tizen::Ui::Scenes::SceneId& previousSceneId,
			const Tizen::Ui::Scenes::SceneId& currentSceneId,
			Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(
			const Tizen::Ui::Scenes::SceneId& currentSceneId,
			const Tizen::Ui::Scenes::SceneId& nextSceneId);
	/* List View */


	// IListViewItemEventListener
	virtual void OnListViewContextItemStateChanged(
			Tizen::Ui::Controls::ListView &listView, int index, int elementId,
			Tizen::Ui::Controls::ListContextItemStatus state);
	virtual void OnListViewItemStateChanged(
			Tizen::Ui::Controls::ListView &listView, int index, int elementId,
			Tizen::Ui::Controls::ListItemStatus status);
	virtual void OnListViewItemSwept(Tizen::Ui::Controls::ListView &listView,
			int index, Tizen::Ui::Controls::SweepDirection direction);

	// IListViewItemProvider
	virtual Tizen::Ui::Controls::ListItemBase* CreateItem(int index,
			int itemWidth);
	virtual bool DeleteItem(int index, Tizen::Ui::Controls::ListItemBase* pItem,
			int itemWidth);
	virtual int GetItemCount(void);
	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
	virtual void OnKeyLongPressed(const Tizen::Ui::Control& source, Tizen::Ui::KeyCode keyCode);
	virtual void OnKeyPressed(const Tizen::Ui::Control& source, Tizen::Ui::KeyCode keyCode);
	virtual void OnKeyReleased(const Tizen::Ui::Control& source, Tizen::Ui::KeyCode keyCode);

	// IHttpTransactionEventListener
		void OnTransactionReadyToRead(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction,
				int availableBodyLen);

		void OnTransactionAborted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction, result r);

		void OnTransactionReadyToWrite(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction,
				int recommendedChunkSize);

		void OnTransactionHeaderCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction,
				int headerLen, bool rs);

		void OnTransactionCompleted(Tizen::Net::Http::HttpSession& httpSession, Tizen::Net::Http::HttpTransaction& httpTransaction);

		void OnTransactionCertVerificationRequiredN(Tizen::Net::Http::HttpSession& httpSession,
				Tizen::Net::Http::HttpTransaction& httpTransaction, Tizen::Base::String* pCert);
};

#endif
