
#ifndef _FILMITEM_H_
#define _FILMITEM_H_

#include <FBase.h>
#include <FUi.h>
#include <FIo.h>

using namespace Tizen::Base;
using namespace Tizen::Base::Collection;
using namespace Tizen::Base::Runtime;
using namespace Tizen::Graphics;
using namespace Tizen::Ui::Controls;

class FilmItem :
	public Tizen::Ui::Controls::Panel,public Tizen::Ui::IActionEventListener
{

// Construction
public:
	FilmItem(void);
	virtual ~FilmItem(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);




// Implementation
protected:
Label *__pName;
Label *__pImage;
// Generated call-back functions
public:

void OnLoadImage(Bitmap& image);
void OnLoadFilmName(String name);
virtual void OnActionPerformed(const Tizen::Ui::Control& source,
			int actionId);





};

#endif
