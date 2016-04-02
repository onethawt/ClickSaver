/* Poly
   Useful
   Lib */

#ifndef __PUL_CLASSES_H__
#define __PUL_CLASSES_H__

#include <pul/types.h>
#include <pul/list.h>

/* "Base" */
#define PU_BASECLASS_ATT	0x10000
#define PU_BASECLASS_MTD	0x11000

#define PUM_NEW						PU_BASECLASS_MTD + 1
#define PUM_DELETE					PU_BASECLASS_MTD + 2
#define PUM_ADDREF					PU_BASECLASS_MTD + 3
#define PUM_REMREF					PU_BASECLASS_MTD + 4
#define PUM_SET						PU_BASECLASS_MTD + 5
#define PUM_GET						PU_BASECLASS_MTD + 6
#define PUM_ADDCHILD				( ( PU_BASECLASS_MTD + 7 ) | PU_DATATYPE_OBJREF )
#define PUM_GETCHILDLIST			PU_BASECLASS_MTD + 8
#define PUM_ADDNOTIFICATION			( ( PU_BASECLASS_MTD + 9 ) | PU_DATATYPE_DESCSTREAM )
#define PUM_REMNOTIFICATION			PU_BASECLASS_MTD + 10

#define PUA_PARENT					PU_BASECLASS_ATT + 1
#define PUA_NOTIFICATION			PU_BASECLASS_ATT + 2

/* "Table" */
#define PU_TABLECLASS_ATT		0x20000
#define PU_TABLECLASS_MTD		0x21000

#define PUA_TABLE_NUMFIELDS			PU_TABLECLASS_ATT + 1
#define PUA_TABLE_NUMRECORDS		PU_TABLECLASS_ATT + 2
#define PUA_TABLE_CURRENTRECORD		PU_TABLECLASS_ATT + 3
#define PUA_TABLE_CURRENTFIELD		PU_TABLECLASS_ATT + 4

#define PUM_TABLE_SETFIELDNAME		PU_TABLECLASS_MTD + 1
#define PUM_TABLE_SETFIELDTYPE		PU_TABLECLASS_MTD + 2
#define PUM_TABLE_GETFIELDS			PU_TABLECLASS_MTD + 3
#define PUM_TABLE_GETFIELDNAME		PU_TABLECLASS_MTD + 4	// Param: field num
#define PUM_TABLE_GETFIELDTYPE		PU_TABLECLASS_MTD + 5	// Param: field num
#define PUM_TABLE_GETFIELDVAL		PU_TABLECLASS_MTD + 6	// Param1: record, Param2: field num
#define PUM_TABLE_GETFIRSTRECORD	PU_TABLECLASS_MTD + 7
#define PUM_TABLE_GETLASTRECORD		PU_TABLECLASS_MTD + 8
#define PUM_TABLE_GETRECORD			PU_TABLECLASS_MTD + 9	// Param: key
#define PUM_TABLE_GETNEXTRECORD		PU_TABLECLASS_MTD + 10	// Param: record
#define PUM_TABLE_GETPREVRECORD		PU_TABLECLASS_MTD + 11	// Param: record
#define PUM_TABLE_NEWRECORD			PU_TABLECLASS_MTD + 12
#define PUM_TABLE_ADDRECORD			PU_TABLECLASS_MTD + 13	// Param: key
#define PUM_TABLE_REMRECORD			PU_TABLECLASS_MTD + 14	// Param: record
#define PUM_TABLE_SETFIELDVAL		PU_TABLECLASS_MTD + 15	// Param1: value
#define PUM_TABLE_CLEAR				PU_TABLECLASS_MTD + 16

typedef struct
{
	PUU8*	pName;
	PUU32	Type;
} pusTableField;

enum
{
	PUFIELD_TYPE_STRING,
	PUFIELD_TYPE_STRINGCOPY,
	PUFIELD_TYPE_U32
};

/* "Container" */
#define PU_CONTAINERCLASS_ATT	0x30000
#define PU_CONTAINERCLASS_MTD	0x31000

#define PUA_CONTAINER_CONTENTS		( ( PU_CONTAINERCLASS_ATT + 1 ) | PU_DATATYPE_OBJREF )

/* "Window" */
#define PU_WINDOWCLASS_ATT	0x40000
#define PU_WINDOWCLASS_MTD	0x41000

#define PUM_WINDOW_CALCMINMAX		PU_WINDOWCLASS_MTD + 1
#define PUM_WINDOW_PRELAYOUT		PU_WINDOWCLASS_MTD + 2
#define PUM_WINDOW_LAYOUT			PU_WINDOWCLASS_MTD + 3
#define PUM_WINDOW_RENDER			PU_WINDOWCLASS_MTD + 4
#define PUM_WINDOW_GETRASTPORT		PU_WINDOWCLASS_MTD + 5
#define PUM_WINDOW_REDRAWRECT		PU_WINDOWCLASS_MTD + 6
#define PUM_WINDOW_MOUSEEVENT		PU_WINDOWCLASS_MTD + 7
#define PUM_WINDOW_KEYBOARDEVENT	PU_WINDOWCLASS_MTD + 8
#define PUM_WINDOW_RECALC			PU_WINDOWCLASS_MTD + 9
#define PUM_WINDOW_GETRECT			PU_WINDOWCLASS_MTD + 10
#define PUM_WINDOW_GETINNERRECT		PU_WINDOWCLASS_MTD + 11

#define PUA_WINDOW_OPENED			PU_WINDOWCLASS_ATT + 1
#define PUA_WINDOW_XPOS				PU_WINDOWCLASS_ATT + 2
#define PUA_WINDOW_YPOS				PU_WINDOWCLASS_ATT + 3
#define PUA_WINDOW_WIDTH			PU_WINDOWCLASS_ATT + 4
#define PUA_WINDOW_HEIGHT			PU_WINDOWCLASS_ATT + 5
#define PUA_WINDOW_TITLE			( ( PU_WINDOWCLASS_ATT + 6 ) | PU_DATATYPE_STRING )
#define PUA_WINDOW_CONTENTS			( ( PU_WINDOWCLASS_ATT + 7 ) | PU_DATATYPE_OBJREF )
#define PUA_WINDOW_ACTIVECONTROL	( ( PU_WINDOWCLASS_ATT + 8 ) | PU_DATATYPE_OBJREF )
#define PUA_WINDOW_CLOSE			PU_WINDOWCLASS_ATT + 9
#define PUA_WINDOW_HORCENTER		PU_WINDOWCLASS_ATT + 10
#define PUA_WINDOW_VERCENTER		PU_WINDOWCLASS_ATT + 11
#define PUA_WINDOW_NOCLOSEBOX		PU_WINDOWCLASS_ATT + 12
#define PUA_WINDOW_FORCETOP			PU_WINDOWCLASS_ATT + 13
#define PUA_WINDOW_ICONIFYBOX		PU_WINDOWCLASS_ATT + 14
#define PUA_WINDOW_ICONIFIED		PU_WINDOWCLASS_ATT + 15
#define PUA_WINDOW_HANDLE			PU_WINDOWCLASS_ATT + 16
#define PUA_WINDOW_PARENTHANDLE		PU_WINDOWCLASS_ATT + 17
#define PUA_WINDOW_DEFERUPDATE		PU_WINDOWCLASS_ATT + 18
#define PUA_WINDOW_POPUP			PU_WINDOWCLASS_ATT + 19

/* "Control" */
#define PU_CONTROLCLASS_ATT	0x50000L
#define PU_CONTROLCLASS_MTD	0x51000L

#define PUM_CONTROL_CALCMINMAX			PU_CONTROLCLASS_MTD + 1
#define PUM_CONTROL_PRELAYOUT			PU_CONTROLCLASS_MTD + 2
#define PUM_CONTROL_LAYOUT				PU_CONTROLCLASS_MTD + 3
#define PUM_CONTROL_RENDER				PU_CONTROLCLASS_MTD + 4
#define PUM_CONTROL_GETINNERRECT		PU_CONTROLCLASS_MTD + 5
#define PUM_CONTROL_GETOUTERRECT		PU_CONTROLCLASS_MTD + 6

#define PUM_CONTROL_MOUSEEVENT			PU_CONTROLCLASS_MTD + 7
#define PUM_CONTROL_KEYBOARDEVENT		PU_CONTROLCLASS_MTD + 8
#define PUM_CONTROL_REDRAW				PU_CONTROLCLASS_MTD + 9
#define PUM_CONTROL_REDRAWINNER			PU_CONTROLCLASS_MTD + 10
#define PUM_CONTROL_RELAYOUT			PU_CONTROLCLASS_MTD + 11
#define PUM_CONTROL_RECALC				PU_CONTROLCLASS_MTD + 12
#define PUM_CONTROL_CLEARBG				PU_CONTROLCLASS_MTD + 13

#define PUA_CONTROL_POSX				( PU_CONTROLCLASS_ATT + 1 )
#define PUA_CONTROL_POSY				( PU_CONTROLCLASS_ATT + 2 )
#define PUA_CONTROL_WIDTH				( PU_CONTROLCLASS_ATT + 3 )
#define PUA_CONTROL_HEIGHT				( PU_CONTROLCLASS_ATT + 4 )
#define PUA_CONTROL_MINWIDTH			( PU_CONTROLCLASS_ATT + 5 )
#define PUA_CONTROL_MAXWIDTH			( PU_CONTROLCLASS_ATT + 6 )
#define PUA_CONTROL_MINHEIGHT			( PU_CONTROLCLASS_ATT + 7 )
#define PUA_CONTROL_MAXHEIGHT			( PU_CONTROLCLASS_ATT + 8 )
#define PUA_CONTROL_WEIGHT				( PU_CONTROLCLASS_ATT + 9 )
#define PUA_CONTROL_HIDDEN				( PU_CONTROLCLASS_ATT + 10 )
#define PUA_CONTROL_KEEPROOM			( PU_CONTROLCLASS_ATT + 11 )
									
#define PUA_CONTROL_FRAME				PU_CONTROLCLASS_ATT + 12
#define PUA_CONTROL_LABEL				( ( PU_CONTROLCLASS_ATT + 13 ) | PU_DATATYPE_STRING )
#define PUA_CONTROL_STATE				PU_CONTROLCLASS_ATT + 14
#define PUA_CONTROL_ISBUTTON			PU_CONTROLCLASS_ATT + 15
#define PUA_CONTROL_ACTIVEWEAK			PU_CONTROLCLASS_ATT + 16
#define PUA_CONTROL_WINDOW				PU_CONTROLCLASS_ATT + 17
#define PUA_CONTROL_CLICKED				PU_CONTROLCLASS_ATT + 18
#define PUA_CONTROL_HASKEYBOARDFOCUS	PU_CONTROLCLASS_ATT + 19
#define PUA_CONTROL_DEFERRELAYOUT		PU_CONTROLCLASS_ATT + 20

/* "Spacer" */
#define PU_SPACERCLASS_ATT		0x60000
#define PU_SPACERCLASS_MTD		0x61000

#define PUA_SPACER_WIDTH			PU_SPACERCLASS_ATT + 1
#define PUA_SPACER_HEIGHT			PU_SPACERCLASS_ATT + 2
#define PUA_SPACER_MINWIDTH			PU_SPACERCLASS_ATT + 3
#define PUA_SPACER_MINHEIGHT		PU_SPACERCLASS_ATT + 4
#define PUA_SPACER_MAXWIDTH			PU_SPACERCLASS_ATT + 5
#define PUA_SPACER_MAXHEIGHT		PU_SPACERCLASS_ATT + 6

/* "Scrolling" */
#define PU_SCROLLINGCLASS_ATT	0x70000
#define PU_SCROLLINGCLASS_MTD	0x71000

#define PUM_SCROLLING_GETVIEWRECT		PU_SCROLLINGCLASS_MTD + 1
#define PUM_SCROLLING_REDRAWINNER		PU_SCROLLINGCLASS_MTD + 2
#define PUM_SCROLLING_MOUSEEVENT		PU_SCROLLINGCLASS_MTD + 3

#define PUA_SCROLLING_VIEWMINWIDTH		PU_SCROLLINGCLASS_ATT + 1
#define PUA_SCROLLING_VIEWMAXWIDTH		PU_SCROLLINGCLASS_ATT + 2
#define PUA_SCROLLING_VIEWMINHEIGHT		PU_SCROLLINGCLASS_ATT + 3
#define PUA_SCROLLING_VIEWMAXHEIGHT		PU_SCROLLINGCLASS_ATT + 4
#define PUA_SCROLLING_WIDTH				PU_SCROLLINGCLASS_ATT + 5
#define PUA_SCROLLING_HEIGHT			PU_SCROLLINGCLASS_ATT + 6
#define PUA_SCROLLING_HORVIS			PU_SCROLLINGCLASS_ATT + 7
#define PUA_SCROLLING_VERVIS			PU_SCROLLINGCLASS_ATT + 8
#define PUA_SCROLLING_POSX				PU_SCROLLINGCLASS_ATT + 9
#define PUA_SCROLLING_POSY				PU_SCROLLINGCLASS_ATT + 10
#define PUA_SCROLLING_AUTOHIDESCROLLERS	PU_SCROLLINGCLASS_ATT + 11
#define PUA_SCROLLING_SHOWHSCROLLER		PU_SCROLLINGCLASS_ATT + 12
#define PUA_SCROLLING_SHOWVSCROLLER		PU_SCROLLINGCLASS_ATT + 13
#define PUA_SCROLLING_NOFRAMES			PU_SCROLLINGCLASS_ATT + 14

/* "Group" */
#define PU_GROUPCLASS_ATT		0x80000
#define PU_GROUPCLASS_MTD		0x81000

/* "HorGroup" */
#define PU_HORGROUPCLASS_ATT	0x90000
#define PU_HORGROUPCLASS_MTD	0x91000

#define PUA_HORGROUP_CENTERMODE		PU_HORGROUPCLASS_ATT + 1
#define PUA_HORGROUP_SPACING		PU_HORGROUPCLASS_ATT + 2
#define PUA_HORGROUP_FIXEDWIDTH		PU_HORGROUPCLASS_ATT + 3
#define PUA_HORGROUP_FIXEDHEIGHT	PU_HORGROUPCLASS_ATT + 4

/* HorGroup centering modes */
enum
{
	PU_HGROUP_CENTER,
	PU_HGROUP_TOP,
	PU_HGROUP_BOTTOM
};

/* "VerGroup" */
#define PU_VERGROUPCLASS_ATT	0xa0000
#define PU_VERGROUPCLASS_MTD	0xa1000

#define PUA_VERGROUP_CENTERMODE		PU_VERGROUPCLASS_ATT + 1
#define PUA_VERGROUP_SPACING		PU_VERGROUPCLASS_ATT + 2
#define PUA_VERGROUP_FIXEDWIDTH		PU_VERGROUPCLASS_ATT + 3
#define PUA_VERGROUP_FIXEDHEIGHT	PU_VERGROUPCLASS_ATT + 4

/* VerGroup centering modes */
enum
{
	PU_VGROUP_CENTER,
	PU_VGROUP_LEFT,
	PU_VGROUP_RIGHT
};

/* "Text" */
#define PU_TEXTCLASS_ATT	0xb0000
#define PU_TEXTCLASS_MTD	0xb1000

#define PUA_TEXT_STRING				( ( PU_TEXTCLASS_ATT + 1 ) | PU_DATATYPE_STRING )
#define PUA_TEXT_CENTERMODE			PU_TEXTCLASS_ATT + 2
#define PUA_TEXT_MINWIDTH			PU_TEXTCLASS_ATT + 3
#define PUA_TEXT_FIXEDWIDTH			PU_TEXTCLASS_ATT + 4

enum
{
	PU_TEXT_CENTER,
	PU_TEXT_LEFT,
	PU_TEXT_RIGHT
};

/* "CheckBox" */
#define PU_CHECKBOXCLASS_ATT	0xc0000
#define PU_CHECKBOXCLASS_MTD	0xc1000

#define PUA_CHECKBOX_CHECKED		PU_CHECKBOXCLASS_ATT + 1
#define PUA_CHECKBOX_LABEL			( ( PU_CHECKBOXCLASS_ATT + 2 ) | PU_DATATYPE_STRING )


/* "Slider" */
#define PU_SLIDERCLASS_ATT		0xd0000
#define PU_SLIDERCLASS_MTD		0xd1000

#define PUA_SLIDER_ISVERTICAL		PU_SLIDERCLASS_ATT + 1
#define PUA_SLIDER_MIN				PU_SLIDERCLASS_ATT + 2
#define PUA_SLIDER_MAX				PU_SLIDERCLASS_ATT + 3
#define PUA_SLIDER_VISIBLE			PU_SLIDERCLASS_ATT + 4
#define PUA_SLIDER_VALUE			PU_SLIDERCLASS_ATT + 5

/* "Register" */
#define PU_REGISTERCLASS_ATT	0xe0000
#define PU_REGISTERCLASS_MTD	0xe1000

#define PUA_REGISTER_FIXEDWIDTH		PU_REGISTERCLASS_ATT + 1
#define PUA_REGISTER_FIXEDHEIGHT	PU_REGISTERCLASS_ATT + 2
#define PUA_REGISTER_CURRENTTAB		PU_REGISTERCLASS_MTD + 3

#define PUM_REGISTER_ADDTAB			PU_REGISTERCLASS_MTD + 1
#define PUM_REGISTER_SETTABOBJECT	( ( PU_REGISTERCLASS_MTD + 2 ) | PU_DATATYPE_OBJREF )

/* "ListView" */
#define PU_LISTVIEWCLASS_ATT	0xf0000
#define PU_LISTVIEWCLASS_MTD	0xf1000

#define PUM_LISTVIEW_ADD			PU_LISTVIEWCLASS_MTD + 1
#define PUM_LISTVIEW_REMOVE			PU_LISTVIEWCLASS_MTD + 2
#define PUM_LISTVIEW_EDIT			PU_LISTVIEWCLASS_MTD + 3
#define PUM_LISTVIEW_SELUP			PU_LISTVIEWCLASS_MTD + 4
#define PUM_LISTVIEW_SELDOWN		PU_LISTVIEWCLASS_MTD + 5

#define PUA_LISTVIEW_TABLE			( ( PU_LISTVIEWCLASS_ATT + 1 ) | PU_DATATYPE_OBJREF )
#define PUA_LISTVIEW_NUMVISIBLE		PU_LISTVIEWCLASS_ATT + 2
#define PUA_LISTVIEW_FIRSTVISIBLE	PU_LISTVIEWCLASS_ATT + 3
#define PUA_LISTVIEW_SHOWSELECTED	PU_LISTVIEWCLASS_ATT + 4
#define PUA_LISTVIEW_EDITABLE		PU_LISTVIEWCLASS_ATT + 5
#define PUA_LISTVIEW_EDITMODE		PU_LISTVIEWCLASS_ATT + 6
#define PUA_LISTVIEW_MUSTSELECT		PU_LISTVIEWCLASS_ATT + 7
#define PUA_LISTVIEW_SELECTED		PU_LISTVIEWCLASS_ATT + 8
#define PUA_LISTVIEW_DOUBLECLICKED	PU_LISTVIEWCLASS_ATT + 9
#define PUA_LISTVIEW_MAXNUMVISIBLE	PU_LISTVIEWCLASS_ATT + 10
#define PUA_LISTVIEW_HOVER			PU_LISTVIEWCLASS_ATT + 11
#define PUA_LISTVIEW_CLICKED		PU_LISTVIEWCLASS_ATT + 12
#define PUA_LISTVIEW_ENTERPRESSED	PU_LISTVIEWCLASS_ATT + 13


/* "TextEntry" */
#define PU_TEXTENTRYCLASS_ATT	0x100000
#define PU_TEXTENTRYCLASS_MTD	0x101000

#define PUA_TEXTENTRY_BUFFERSIZE	PU_TEXTENTRYCLASS_ATT + 1
#define PUA_TEXTENTRY_BUFFER		( ( PU_TEXTENTRYCLASS_ATT + 2 ) | PU_DATATYPE_STRING )
#define PUA_TEXTENTRY_READONLY		PU_TEXTENTRYCLASS_ATT + 3
#define PUA_TEXTENTRY_EDITMODE		PU_TEXTENTRYCLASS_ATT + 4
#define PUA_TEXTENTRY_HILIGHT		PU_TEXTENTRYCLASS_ATT + 5
#define PUA_TEXTENTRY_NUMERIC		PU_TEXTENTRYCLASS_ATT + 6
#define PUA_TEXTENTRY_VALUE			PU_TEXTENTRYCLASS_ATT + 7
#define PUA_TEXTENTRY_MIN			PU_TEXTENTRYCLASS_ATT + 8
#define PUA_TEXTENTRY_MAX			PU_TEXTENTRYCLASS_ATT + 9
#define PUA_TEXTENTRY_FORMAT		PU_TEXTENTRYCLASS_ATT + 10

enum
{
	PUFORMAT_DECIMAL,
	PUFORMAT_HEX
};

/* "Image" */
#define PU_IMAGECLASS_ATT	0x110000
#define PU_IMAGECLASS_MTD	0x111000

#define PUA_IMAGE_WIDTH				PU_IMAGECLASS_ATT + 1
#define PUA_IMAGE_HEIGHT			PU_IMAGECLASS_ATT + 2
#define PUA_IMAGE_PIXFORMAT			PU_IMAGECLASS_ATT + 3
#define PUA_IMAGE_DATA				PU_IMAGECLASS_ATT + 4

/* "Fold" */
#define PU_FOLDCLASS_ATT	0x120000
#define PU_FOLDCLASS_MTD	0x121000

#define PUA_FOLD_CONTENTS			( ( PU_FOLDCLASS_ATT + 1 ) | PU_DATATYPE_OBJREF )
#define PUA_FOLD_LABEL				PU_FOLDCLASS_ATT + 2
#define PUA_FOLD_FOLDED				PU_FOLDCLASS_ATT + 3
#define PUA_FOLD_HILIGHT			PU_FOLDCLASS_ATT + 4

/* "TextArea" */
#define PU_TEXTAREACLASS_ATT	0x130000
#define PU_TEXTAREACLASS_MTD	0x131000

#define PUM_TEXTAREA_APPENDBUFFER	PU_TEXTAREACLASS_MTD + 1

#define PUA_TEXTAREA_BUFFER			PU_TEXTAREACLASS_ATT + 1
#define PUA_TEXTAREA_WRAPMODE		PU_TEXTAREACLASS_ATT + 2
#define PUA_TEXTAREA_FORCEHEIGHT	PU_TEXTAREACLASS_ATT + 3
#define PUA_TEXTAREA_READONLY		PU_TEXTAREACLASS_ATT + 4
#define PUA_TEXTAREA_NOCUTPASTE		PU_TEXTAREACLASS_ATT + 5
#define PUA_TEXTAREA_CENTERMODE		PU_TEXTAREACLASS_ATT + 6
#define PUA_TEXTAREA_FONT			PU_TEXTAREACLASS_ATT + 7

enum
{
	PUWRAPMODE_NONE,
	PUWRAPMODE_CHARACTER,
	PUWRAPMODE_WORD
};

enum
{
	PUTA_CENTERMODE_LEFT,
	PUTA_CENTERMODE_RIGHT,	// NYI
	PUTA_CENTERMODE_CENTER,
	PUTA_CENTERMODE_JUSTIFY	// NYI
};

/* "ComboBox" */
#define PU_COMBOBOXCLASS_ATT	0x140000
#define PU_COMBOBOXCLASS_MTD	0x141000

#define PUM_COMBOBOX_NOTIFYSELECT	PU_COMBOBOXCLASS_MTD + 1

#define PUA_COMBOBOX_TABLE			( ( PU_COMBOBOXCLASS_ATT + 1 ) | PU_DATATYPE_OBJREF )
#define PUA_COMBOBOX_SELECTED		PU_COMBOBOXCLASS_ATT + 2


#endif