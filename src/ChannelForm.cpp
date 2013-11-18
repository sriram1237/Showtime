#include "AppResourceId.h"
#include "ChannelForm.h"
#include "ShowTimeRegister.h"

#include <FAppUiApp.h>
#include <FApp.h>

using namespace Tizen::App;
using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;
using namespace Tizen::Ui::Scenes;

ChannelForm::ChannelForm(void) {
	__pListView = null;
	__pItemContext = null;
	__pLogo = null;
	pAppResource = null;
}

ChannelForm::~ChannelForm(void) {
}

bool ChannelForm::Initialize() {
	Form::Construct(IDF_CHANNELFORM);
	return true;
}

result ChannelForm::OnInitializing(void) {
	result r = E_SUCCESS;
	pAppResource = Application::GetInstance()->GetAppResource();

	// Creates an instance of ListView
	__pListView = new ListView();
	__pListView->Construct(
			Rectangle(0, 0, GetClientAreaBounds().width,
					GetClientAreaBounds().height), true, false);
	__pListView->SetItemProvider(*this);
	__pListView->AddListViewItemEventListener(*this);
	__pListView->SetBackgroundColor(Color::GetColor(COLOR_ID_GREY));

	// Adds the list view to the form
	AddControl(__pListView);
	// Creates an instance of ListContextItem
	__pItemContext = new ListContextItem();
	__pItemContext->Construct();

	SetFormBackEventListener(this);

	AddKeyEventListener(*this);

	return r;
}

result ChannelForm::OnTerminating(void) {
	result r = E_SUCCESS;
	return r;
}

void ChannelForm::OnActionPerformed(const Tizen::Ui::Control& source,
		int actionId) {

}
void ChannelForm::OnSceneActivatedN(
		const Tizen::Ui::Scenes::SceneId& previousSceneId,
		const Tizen::Ui::Scenes::SceneId& currentSceneId,
		Tizen::Base::Collection::IList* pArgs) {
	AppLog("On Screen Active");
	const Form* pForm = dynamic_cast<Form*>(GetParent());
	AppAssert(pForm);

	Header* pHeader = pForm->GetHeader();
	AppAssert(pHeader);
}

void ChannelForm::OnSceneDeactivated(
		const Tizen::Ui::Scenes::SceneId& currentSceneId,
		const Tizen::Ui::Scenes::SceneId& nextSceneId) {

}

// IListViewItemEventListener implementation
void ChannelForm::OnListViewItemStateChanged(ListView &listView, int index,
		int elementId, ListItemStatus status) {
	SceneManager* pSceneManager = SceneManager::GetInstance();
	AppAssert(pSceneManager);
	switch (status) {
	case LIST_ITEM_STATUS_SELECTED: {
		//ChannelForm::requestHttpGet(
		//		L"http://www.musicnfilms.com/wp-content/uploads/2013/01/Hollywood-Sci-fic-Movies-list.jpg");

		pSceneManager->GoForward(
				ForwardSceneTransition(SCENE_MAIN_FORM,
						SCENE_TRANSITION_ANIMATION_TYPE_LEFT));

		AppLog(
				"index = %d, elementId = %d LIST_ITEM_STATUS_SELECTED", index, elementId);
	}
		break;

	case LIST_ITEM_STATUS_HIGHLIGHTED:
		AppLog(
				"index = %d, elementId = %d LIST_ITEM_STATUS_HIGHLIGHTED", index, elementId);
		break;
	case LIST_ITEM_STATUS_CHECKED:
		AppLog(
				"index = %d, elementId = %d LIST_ITEM_STATUS_CHECKED", index, elementId);
		break;
	case LIST_ITEM_STATUS_UNCHECKED:
		AppLog(
				"index = %d, elementId = %d LIST_ITEM_STATUS_UNCHECKED", index, elementId);
		break;
	case LIST_ITEM_STATUS_MORE:
		AppLog(
				"index = %d, elementId = %d LIST_ITEM_STATUS_MORE", index, elementId);
		break;
	default:
		AppLog("some other state");
		break;
	}
}

void ChannelForm::OnListViewContextItemStateChanged(ListView &listView,
		int index, int elementId, ListContextItemStatus state) {
	AppLog(__PRETTY_FUNCTION__);
	/*	switch (elementId) {
	 case ID_CONTEXT_ITEM_1: {
	 // ....
	 }
	 break;
	 case ID_CONTEXT_ITEM_2: {
	 // ....
	 }
	 break;
	 default:
	 break;
	 }*/
}

void ChannelForm::OnListViewItemSwept(ListView &listView, int index,
		SweepDirection direction) {
	// ....
}

String logo[] = { "hbo", "movies_now", "sony_max", "axn", "star_world",
		"history", "disney_xd", "espn", "star_movies", "cn" };
String channels[] = { "HBO", "Movies Now", "Sony Max", "AXN", "Star World",
		"History", "Disney XD", "ESPN", "Star Movies", "Cartoon Network" };

// IListViewItemProvider implementation
ListItemBase*
ChannelForm::CreateItem(int index, int itemWidth) {
	// Creates an instance of CustomItem
	CustomItem* pItem = new CustomItem();
	ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;

	style = LIST_ANNEX_STYLE_NORMAL;
	AppLog("Item Width:%d", itemWidth);
	style = LIST_ANNEX_STYLE_NORMAL;
	pItem->Construct(Dimension(itemWidth, 140), style);

	__pLogo = pAppResource->GetBitmapN(L"" + logo[index] + L".jpg");

	pItem->AddElement(Rectangle(10, 20, 95, 100), ID_FORMAT_BITMAP, *__pLogo,
			null, null);
	pItem->AddElement(Rectangle(120, 45, 650, 50), 100, L"" + channels[index],
			true);

	pItem->SetContextItem(__pItemContext);

	return pItem;
}

bool ChannelForm::DeleteItem(int index, ListItemBase* pItem, int itemWidth) {
	delete pItem;
	pItem = null;
	return true;
}

int ChannelForm::GetItemCount(void) {
	return 10;
}

void ChannelForm::OnFormBackRequested(Tizen::Ui::Controls::Form& source) {
	AppLog("Terminate");
	Tizen::App::Application* pApp = Application::GetInstance();
	AppAssert(pApp);
	pApp->Terminate();

}

void ChannelForm::OnKeyLongPressed(const Tizen::Ui::Control& source,
		Tizen::Ui::KeyCode keyCode) {
	// TODO: Add your implementation codes here

}

void ChannelForm::OnKeyPressed(const Tizen::Ui::Control& source,
		Tizen::Ui::KeyCode keyCode) {
	// TODO: Add your implementation codes here

}

void ChannelForm::OnKeyReleased(const Tizen::Ui::Control& source,
		Tizen::Ui::KeyCode keyCode) {
	// TODO: Add your implementation codes here

}

void ChannelForm::requestHttpGet(String url) {
	AppLog("Request Call");

	String uri = url;
	HttpSession* pSession = null;
	HttpTransaction* pTransaction = null;
	String* pProxyAddr = null;
	String hostAddr(url);

	pSession = new HttpSession();
	mHttpSession = new HttpSession();

	pSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, null, uri, null);

	// Open a new HttpTransaction.
	pTransaction = pSession->OpenTransactionN();

	pTransaction->AddHttpTransactionListener(*this);

	HttpRequest* pRequest = pTransaction->GetRequest();
	pRequest->SetUri(uri);
	pRequest->SetMethod(NET_HTTP_METHOD_GET);

	// Submit the HttpTransaction.
	pTransaction->Submit();
	AppLog("Submit");

	/*HttpTransaction * pTransaction = mHttpSession->OpenTransactionN();
	 AppLog("HTTP Transaaction");
	 pTransaction->AddHttpTransactionListener(*this);
	 AppLog("ADD HTTP Transaaction");
	 HttpRequest * pRequest = pTransaction->GetRequest();
	 AppLog("  HTTP Request");
	 pRequest->SetUri(uri);
	 AppLog("  HTTP  URI");
	 pRequest->SetMethod(NET_HTTP_METHOD_GET);
	 AppLog("GETMethod");
	 HttpHeader * pHeader = pRequest->GetHeader();
	 AppLog("HTTP Header");
	 //pTransaction->SetUserObject(userObjects);
	 pTransaction->Submit();
	 AppLog("Submit");*/
}

void ChannelForm::OnTransactionReadyToRead(HttpSession& httpSession,
		HttpTransaction& httpTransaction, int availableBodyLen) {
	AppLog("OnTransactionReadyToRead");

	HttpResponse* pHttpResponse = httpTransaction.GetResponse();
	if (pHttpResponse->GetHttpStatusCode() == HTTP_STATUS_OK) {
		HttpHeader* pHttpHeader = pHttpResponse->GetHeader();
		if (pHttpHeader != null) {
			String* tempHeaderString = pHttpHeader->GetRawHeaderN();
			ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();
			AppLog("Buffer");
			String text(L"Read Body Length: ");
			text.Append(availableBodyLen);
			AppLog("%S", pBuffer->GetPointer());
			//   __pEditArea->SetText(text);
			//  Draw();

			delete tempHeaderString;
			delete pBuffer;
		}
	}
}

void ChannelForm::OnTransactionAborted(
		Tizen::Net::Http::HttpSession& httpSession,
		Tizen::Net::Http::HttpTransaction& httpTransaction, result r) {

	AppLog("OnTransactionAborted(%s)", GetErrorMessage(r));

	HttpResponse* pHttpResponse = httpTransaction.GetResponse();

	delete &pHttpResponse;

}

void ChannelForm::OnTransactionReadyToWrite(
		Tizen::Net::Http::HttpSession& httpSession,
		Tizen::Net::Http::HttpTransaction& httpTransaction,
		int recommendedChunkSize) {
	AppLog("OnTransactionReadyToWrite");
}

void ChannelForm::OnTransactionHeaderCompleted(
		Tizen::Net::Http::HttpSession& httpSession,
		Tizen::Net::Http::HttpTransaction& HttpTransaction, int headerLen,
		bool authRequired) {
	AppLog("OnTransactionHeaderCompleted");
}

void ChannelForm::OnTransactionCompleted(
		Tizen::Net::Http::HttpSession& httpSession,
		Tizen::Net::Http::HttpTransaction& httpTransaction) {
	AppLog("OnTransactionCompleted");

	HttpResponse* pHttpResponse = httpTransaction.GetResponse();
	AppLog(
			"OnTransactionCompleted responseCode : %d", pHttpResponse->GetHttpStatusCode());
	if (pHttpResponse->GetHttpStatusCode() == HTTP_STATUS_OK) {
		HttpHeader* pHttpHeader = pHttpResponse->GetHeader();

		if (pHttpHeader != null) {
			String* tempHeaderString = pHttpHeader->GetRawHeaderN();
			ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();

			char * pTemp = new char[pBuffer->GetLimit() + 1];
			pBuffer->SetPosition(0);
			pBuffer->GetArray((byte*) pTemp, 0, pBuffer->GetLimit());
			pTemp[pBuffer->GetLimit()] = '\0';

			String response = String(pTemp);
			AppLog(
					"OnTransactionCompleted response : %ls", response.GetPointer());

			delete[] pTemp;
			delete tempHeaderString;
			delete pBuffer;
		}
	} else {
		HttpHeader* pHttpHeader = pHttpResponse->GetHeader();
		if (pHttpHeader != null) {
			String* tempHeaderString = pHttpHeader->GetRawHeaderN();
			ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();

			char * pTemp = new char[pBuffer->GetLimit() + 1];
			pBuffer->SetPosition(0);
			pBuffer->GetArray((byte*) pTemp, 0, pBuffer->GetLimit());
			pTemp[pBuffer->GetLimit()] = '\0';

			String response = String(pTemp);
			AppLog(
					"OnTransactionCompleted response : %ls", response.GetPointer());
		}

	}

	delete &httpTransaction;
}

void ChannelForm::OnTransactionCertVerificationRequiredN(
		Tizen::Net::Http::HttpSession& httpSession,
		Tizen::Net::Http::HttpTransaction& httpTransaction,
		Tizen::Base::String* pCert) {
	AppLog("OnTransactionCertVerificationRequiredN");

	httpTransaction.Resume();
	delete pCert;
}
