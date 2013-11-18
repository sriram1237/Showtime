/*
 * ShowTimeRegister.h
 *
 *  Created on: Jun 12, 2013
 *      Author: surendran
 */

#ifndef SHOWTIMEREGISTER_H_
#define SHOWTIMEREGISTER_H_

extern const wchar_t* SCENE_MAIN_FORM;
extern const wchar_t* SCENE_FEATURE_FORM;

extern const wchar_t* SCENE_UPCOMING_TAB;
extern const wchar_t* SCENE_CHANNEL_FORM;
extern const wchar_t* SCENE_METDATA_FORM;
extern const wchar_t* SCENE_SETTINGS_FORM;

class ShowTimeRegister {
public:
	static void RegisterAllScenes(void);
	ShowTimeRegister();
	virtual ~ShowTimeRegister();
};

#endif /* SHOWTIMEREGISTER_H_ */
