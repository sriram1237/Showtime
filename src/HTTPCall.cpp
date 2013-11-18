/*
 * HTTPCall.cpp
 *
 *  Created on: Jun 17, 2013
 *      Author: surendran
 */

#include "HTTPCall.h"
#include <FApp.h>
#include <FBase.h>
#include <FNet.h>
#include <FUi.h>

using namespace Tizen::Net::Http;
using namespace Tizen::Base;

const static wchar_t* HTTP_CLIENT_HOST_ADDRESS = L"https://www.tizen.org";
const static wchar_t* HTTP_CLIENT_REQUEST_URI = L"www.tizen.org";
HTTPCall::HTTPCall() {
	// TODO Auto-generated constructor stub
	__pHttpSession = null;
	httpTransaction = null;

}

HTTPCall::~HTTPCall() {
	// TODO Auto-generated destructor stub
}

result HTTPCall::RequestHttpGet(void) {
	result r = E_SUCCESS;
	Tizen::Net::Http::HttpTransaction* httpTransaction = null;
	Tizen::Net::Http::HttpRequest* pHttpRequest = null;

	if (__pHttpSession == null) {
		__pHttpSession = new (std::nothrow) HttpSession();

		r = __pHttpSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, null,
				HTTP_CLIENT_HOST_ADDRESS, null);
	}
	httpTransaction = __pHttpSession->OpenTransactionN();

	r = httpTransaction->AddHttpTransactionListener(*this);
	pHttpRequest = const_cast<HttpRequest*>(httpTransaction->GetRequest());

	r = pHttpRequest->SetUri(HTTP_CLIENT_REQUEST_URI);

	r = pHttpRequest->SetMethod(NET_HTTP_METHOD_GET);

	r = httpTransaction->Submit();
	AppLog("Request call");

	return r;
}

void HTTPCall::OnTransactionReadyToRead(HttpSession& httpSession,
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

void HTTPCall::OnTransactionAborted(Tizen::Net::Http::HttpSession& httpSession,
		Tizen::Net::Http::HttpTransaction& HttpTransaction, result r) {

	AppLog("OnTransactionAborted(%s)", GetErrorMessage(r));

	HttpResponse* httpResponse = httpTransaction->GetResponse();



	delete &httpTransaction;

}

void HTTPCall::OnTransactionReadyToWrite(
		Tizen::Net::Http::HttpSession& httpSession,
		Tizen::Net::Http::HttpTransaction& httpTransaction,
		int recommendedChunkSize) {
	AppLog("OnTransactionReadyToWrite");
}

void HTTPCall::OnTransactionHeaderCompleted(
		Tizen::Net::Http::HttpSession& httpSession,
		Tizen::Net::Http::HttpTransaction& HttpTransaction, int headerLen,
		bool authRequired) {
	AppLog("OnTransactionHeaderCompleted");
}

void HTTPCall::OnTransactionCompleted(
		Tizen::Net::Http::HttpSession& httpSession,
		Tizen::Net::Http::HttpTransaction& httpTransaction) {
	AppLog("OnTransactionCompleted");

	HttpResponse* pHttpResponse = httpTransaction.GetResponse();
	AppLog("OnTransactionCompleted responseCode : %d", pHttpResponse->GetHttpStatusCode());
	if (pHttpResponse->GetHttpStatusCode() == HTTP_STATUS_OK)
	{
		HttpHeader* pHttpHeader = pHttpResponse->GetHeader();
		if (pHttpHeader != null)
		{
			String* tempHeaderString = pHttpHeader->GetRawHeaderN();
			ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();

			char * pTemp = new char[pBuffer->GetLimit() + 1];
			pBuffer->SetPosition(0);
			pBuffer->GetArray((byte*) pTemp, 0, pBuffer->GetLimit());
			pTemp[pBuffer->GetLimit()] = '\0';

			String response = String(pTemp);
			AppLog("OnTransactionCompleted response : %ls", response.GetPointer());


			delete[] pTemp;
			delete tempHeaderString;
			delete pBuffer;
		}
	}
	else
	{
		HttpHeader* pHttpHeader = pHttpResponse->GetHeader();
		if (pHttpHeader != null)
		{
			String* tempHeaderString = pHttpHeader->GetRawHeaderN();
			ByteBuffer* pBuffer = pHttpResponse->ReadBodyN();

			char * pTemp = new char[pBuffer->GetLimit() + 1];
			pBuffer->SetPosition(0);
			pBuffer->GetArray((byte*) pTemp, 0, pBuffer->GetLimit());
			pTemp[pBuffer->GetLimit()] = '\0';

			String response = String(pTemp);
			AppLog("OnTransactionCompleted response : %ls", response.GetPointer());
		}


	}

	delete &httpTransaction;
}

void HTTPCall::OnTransactionCertVerificationRequiredN(
		Tizen::Net::Http::HttpSession& httpSession,
		Tizen::Net::Http::HttpTransaction& httpTransaction,
		Tizen::Base::String* pCert) {
	AppLog("OnTransactionCertVerificationRequiredN");

		httpTransaction.Resume();
		delete pCert;
}
void HTTPCall::OnActionPerformed(const Tizen::Ui::Control& source,
		int actionId) {

}
