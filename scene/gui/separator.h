/*************************************************************************/
/*  separator.h                                                          */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                    http://www.godotengine.org                         */
/*************************************************************************/
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                 */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/
#ifndef SEPARATOR_H
#define SEPARATOR_H

/**
	@author Juan Linietsky <reduzio@gmail.com>
*/

#include "scene/gui/control.h"
#include "scene/gui/base_button.h"

class Separator : public Control {

	OBJ_TYPE( Separator, Control );


protected:

	Orientation orientation;
	void _notification(int p_what);
public:

	virtual Size2 get_minimum_size() const;

	Separator();
	~Separator();

};

class VSeparator : public Separator {

	OBJ_TYPE( VSeparator, Separator );

public:

	VSeparator();

};

class HSeparator : public Separator {

	OBJ_TYPE( HSeparator, Separator );

public:

	HSeparator();

};

class CollapsibleVSeparator : public VSeparator {

	OBJ_TYPE( CollapsibleVSeparator, VSeparator );

	List<Control *> controls;
	BaseButton *toggle_button;

	bool collapsed;
	bool hovering;

	void set_hovering(bool p_hovered);

protected:

	static void _bind_methods();
	void _notification(int p_what);

public:

	virtual Size2 get_minimum_size() const;

	void set_collapsed(bool p_toggled);
	void add_control(Control *p_control);
	void remove_control(Control *p_control);

	CollapsibleVSeparator();

};

#endif
