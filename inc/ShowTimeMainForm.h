
#ifndef _SHOWTIMEMAINFORM_H_
#define _SHOWTIMEMAINFORM_H_


#include <FBase.h>
#include <FUi.h>
#include <FGraphics.h>
#include <FMedia.h>
#include <FSystem.h>
#include <FIo.h>
#include <FApp.h>

using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Base::Runtime;
using namespace Tizen::Ui;
using namespace Tizen::Ui::Controls;
using namespace Tizen::Graphics;
using namespace Tizen::Media;
using namespace Tizen::System;
using namespace Tizen::Io;
using namespace Tizen::App;


class ShowTimeMainForm :
	public Tizen::Ui::Controls::Form,
 	public Tizen::Ui::IActionEventListener,
 	public Tizen::Ui::Controls::IFormBackEventListener
{

// Construction
public:
	ShowTimeMainForm(void);
	virtual ~ShowTimeMainForm(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:
	Label *__pButton1;		// Button 1
	Label *__pButton2;		// Button 2
	Label *__pButton3;		// Button 3
	Label* __pLabelLog;		// Log

private:
	static Bitmap *LoadBitmap(const String &strPath);
	static HashMap __loadedBitmaps;
	static bool __initialized;
	static Mutex __mutex;
	Bitmap *__pBitmap[12];
	Bitmap *__pIcon;
// Generated call-back functions
public:

	void Init_HashMap();
	static void Finish_HashMap();
	Bitmap *GetBitmap(const String &strPath);
	void LoadBitmap();
	void ClearBitmap();
	virtual void OnActionPerformed(const Tizen::Ui::Control& source, int actionId);
	virtual void OnSceneActivatedN(
			const Tizen::Ui::Scenes::SceneId& previousSceneId,
			const Tizen::Ui::Scenes::SceneId& currentSceneId,
			Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(
			const Tizen::Ui::Scenes::SceneId& currentSceneId,
			const Tizen::Ui::Scenes::SceneId& nextSceneId);

	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
};

#endif
