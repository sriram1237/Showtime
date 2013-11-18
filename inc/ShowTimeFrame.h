#ifndef _SHOWTIMEFRAME_H_
#define _SHOWTIMEFRAME_H_

#include <FBase.h>
#include <FUi.h>

class ShowTimeFrame
	: public Tizen::Ui::Controls::Frame
{
public:
	ShowTimeFrame(void);
	virtual ~ShowTimeFrame(void);

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif	//_SHOWTIMEFRAME_H_
