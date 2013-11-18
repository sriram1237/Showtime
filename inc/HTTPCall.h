/*
 * HTTPCall.h
 *
 *  Created on: Jun 17, 2013
 *      Author: surendran
 */

#ifndef HTTPCALL_H_
#define HTTPCALL_H_
#include <FApp.h>
#include <FBase.h>
#include <FNet.h>
#include <FUi.h>

class HTTPCall : public Tizen::Ui::IActionEventListener,
   public Tizen::Net::Http::IHttpTransactionEventListener{
public:
	HTTPCall();
	virtual ~HTTPCall();

protected:
	 Tizen::Net::Http::HttpSession* __pHttpSession;
private:
	 Tizen::Net::Http::HttpTransaction* httpTransaction;

public:
	 // Basic event handlers are declared
	 result RequestHttpGet();

	      // IHttpTransactionEventListener
	      virtual void OnTransactionReadyToRead(Tizen::Net::Http::HttpSession& httpSession,
	                                            Tizen::Net::Http::HttpTransaction& httpTransaction,
	                                            int availableBodyLen);

	      virtual void OnTransactionAborted(Tizen::Net::Http::HttpSession& httpSession,
	                                        Tizen::Net::Http::HttpTransaction& httpTransaction, result r);

	      virtual void OnTransactionReadyToWrite(Tizen::Net::Http::HttpSession& httpSession,
	                                             Tizen::Net::Http::HttpTransaction& httpTransaction,
	                                             int recommendedChunkSize);

	      virtual void OnTransactionHeaderCompleted(Tizen::Net::Http::HttpSession& httpSession,
	                                                Tizen::Net::Http::HttpTransaction& httpTransaction,
	                                                int headerLen, bool authRequired);

	      virtual void OnTransactionCompleted(Tizen::Net::Http::HttpSession& httpSession,
	                                          Tizen::Net::Http::HttpTransaction& httpTransaction);

	      virtual void OnTransactionCertVerificationRequiredN(Tizen::Net::Http::HttpSession& httpSession,
	                                                          Tizen::Net::Http::HttpTransaction& httpTransaction,
	                                                          Tizen::Base::String* pCert);
	      virtual void OnActionPerformed(const Tizen::Ui::Control& source,
	      			int actionId);

};

#endif /* HTTPCALL_H_ */
