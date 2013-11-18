#ifndef _METADATAFORM_H_
#define _METADATAFORM_H_

#include <FBase.h>
#include <FUi.h>

class MetaDataForm: public Tizen::Ui::Controls::Form,
		public Tizen::Ui::Scenes::ISceneEventListener,
		public Tizen::Ui::Scenes::ISceneAnimationProvider,
		public Tizen::Ui::Controls::IFormBackEventListener {

// Construction
public:
	MetaDataForm(void);
	virtual ~MetaDataForm(void);
	bool Initialize();
	result OnInitializing(void);
	result OnTerminating(void);

// Implementation
protected:

// Generated call-back functions
public:
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

	virtual void OnFormBackRequested(Tizen::Ui::Controls::Form& source);
};

#endif
