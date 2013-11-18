#ifndef _FEATUREFORM_H_
#define _FEATUREFORM_H_

#include <FBase.h>
#include <FUi.h>

class FeatureForm: public Tizen::Ui::Controls::Form,
		public Tizen::Ui::IActionEventListener,
		public Tizen::Ui::Controls::IFormBackEventListener,
		public Tizen::Ui::Scenes::ISceneEventListener,
		public Tizen::Ui::Scenes::ISceneAnimationProvider {

// Construction
public:

	FeatureForm(void);
	virtual ~FeatureForm(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);
	// ISceneEventListener
	virtual void OnSceneActivatedN(
			const Tizen::Ui::Scenes::SceneId& previousSceneId,
			const Tizen::Ui::Scenes::SceneId& currentSceneId,
			Tizen::Base::Collection::IList* pArgs);
	virtual void OnSceneDeactivated(
			const Tizen::Ui::Scenes::SceneId& currentSceneId,
			const Tizen::Ui::Scenes::SceneId& nextSceneId);
	// ISceneAnimationProvider
	virtual void PrepareAnimation(const Tizen::Ui::Scenes::SceneId& sceneId,
			Tizen::Base::Collection::IList* pArgs,
			Tizen::Ui::Scenes::SceneTransitionAnimationType type,
			bool formTransition);

// Implementation
protected:

private:
//	static const int ID_TABBAR_ITEM1 = 100;
	//  static const int ID_TABBAR_ITEM2 = 101;
	//    static const int ID_TABBAR_ITEM3 = 102;
	Tizen::Ui::Controls::TabBar *__pTabBar;

// Generated call-back functions
public:

	virtual void OnActionPerformed(const Tizen::Ui::Control& source,
			int actionId);

	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
};

#endif
