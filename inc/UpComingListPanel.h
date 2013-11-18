/*
 * UpComingListPanel.h
 *
 *  Created on: Jun 17, 2013
 *      Author: surendran
 */

#ifndef UPCOMINGLISTPANEL_H_
#define UPCOMINGLISTPANEL_H_

#include <FApp.h>
#include <FUi.h>

using namespace Tizen::Base::Collection;
class UpComingListPanel: public Tizen::Ui::Controls::Panel,
		public Tizen::Ui::IActionEventListener,
		public Tizen::Ui::Scenes::ISceneEventListener,
		public Tizen::Ui::Controls::IListViewItemEventListener,
		public Tizen::Ui::Controls::IListViewItemProvider

{
public:
	UpComingListPanel(void) ;
	virtual ~UpComingListPanel();
	bool Initialize();
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
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
private:
	 static const int ID_FORMAT_STRING = 100;
	    static const int ID_FORMAT_BITMAP = 101;
	    static const int ID_CONTEXT_ITEM_1 = 103;
	    static const int ID_CONTEXT_ITEM_2 = 104;

	    Tizen::Graphics::Bitmap* __pHome;
	    Tizen::Graphics::Bitmap* __pMsg;
	    Tizen::Graphics::Bitmap* __pAlarm;
	    Tizen::Graphics::Bitmap* __pCall;

	    Tizen::Graphics::Bitmap* __pShow0;
	    Tizen::Graphics::Bitmap* __pShow1;
	    Tizen::Graphics::Bitmap* __pShow2;
	    Tizen::Graphics::Bitmap* __pShow3;
	    Tizen::Graphics::Bitmap* __pShow4;
	    Tizen::Graphics::Bitmap* __pShow5;
	    Tizen::Graphics::Bitmap* __pShow6;
	    Tizen::Graphics::Bitmap* __pShow7;
	    Tizen::Graphics::Bitmap* __pShow8;
	    Tizen::Graphics::Bitmap* __pShow9;
	    Tizen::Graphics::Bitmap* __pShow10;

	Tizen::Ui::Controls::ListView* __pListView;
	Tizen::Ui::Controls::ListContextItem* __pItemContext;

};

#endif /* UPCOMINGLISTPANEL_H_ */
