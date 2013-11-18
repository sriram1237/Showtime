#ifndef _SETTINGSFORM_H_
#define _SETTINGSFORM_H_

#include <FBase.h>
#include <FUi.h>

class SettingsForm: public Tizen::Ui::Controls::Form,
		public Tizen::Ui::Controls::IFormBackEventListener,
		public Tizen::Ui::Controls::IListViewItemEventListener,
		public Tizen::Ui::Controls::IListViewItemProvider {

// Construction
public:
	SettingsForm(void);
	virtual ~SettingsForm(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:
private:
	Tizen::Ui::Controls::ListView* __pListView;
	Tizen::Ui::Controls::ListContextItem* __pItemContext;

// Generated call-back functions
public:
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
};

#endif
