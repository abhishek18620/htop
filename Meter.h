/* Do not edit this file. It was automatically generated. */

#ifndef HEADER_Meter
#define HEADER_Meter
/*
htop - Meter.h
(C) 2004-2011 Hisham H. Muhammad
Released under the GNU GPL, see the COPYING file
in the source distribution for its full text.
*/

#define METER_BUFFER_LEN 256

#define GRAPH_DELAY (DEFAULT_DELAY/2)

#include "ListItem.h"

#include <sys/time.h>

typedef struct Meter_ Meter;

typedef void(*Meter_Init)(Meter*);
typedef void(*Meter_Done)(Meter*);
typedef void(*Meter_UpdateMode)(Meter*, int);
typedef void(*Meter_SetValues)(Meter*, char*, int);
typedef void(*Meter_Draw)(Meter*, int, int, int);

typedef struct MeterClass_ {
   ObjectClass super;
   const Meter_Init init;
   const Meter_Done done;
   const Meter_UpdateMode updateMode;
   const Meter_Draw draw;
   const Meter_SetValues setValues;
   const int defaultMode;
   const double total;
   const int* attributes;
   const char* name;
   const char* uiName;
   const char* caption;
   const char* description;
   const char maxItems;
   char curItems;
} MeterClass;

#define As_Meter(this_)                ((MeterClass*)((this_)->super.klass))
#define Meter_initFn(this_)            As_Meter(this_)->init
#define Meter_init(this_)              As_Meter(this_)->init((Meter*)(this_))
#define Meter_done(this_)              As_Meter(this_)->done((Meter*)(this_))
#define Meter_updateModeFn(this_)      As_Meter(this_)->updateMode
#define Meter_updateMode(this_, m_)    As_Meter(this_)->updateMode((Meter*)(this_), m_)
#define Meter_drawFn(this_)            As_Meter(this_)->draw
#define Meter_doneFn(this_)            As_Meter(this_)->done
#define Meter_setValues(this_, c_, i_) As_Meter(this_)->setValues((Meter*)(this_), c_, i_)
#define Meter_defaultMode(this_)       As_Meter(this_)->defaultMode
#define Meter_getItems(this_)          As_Meter(this_)->curItems
#define Meter_setItems(this_, n_)      As_Meter(this_)->curItems = (n_)
#define Meter_attributes(this_)        As_Meter(this_)->attributes
#define Meter_name(this_)              As_Meter(this_)->name
#define Meter_uiName(this_)            As_Meter(this_)->uiName

struct Meter_ {
   Object super;
   Meter_Draw draw;
   
   char* caption;
   int mode;
   int param;
   void* drawData;
   int h;
   struct ProcessList_* pl;
   double* values;
   double total;
};

typedef struct MeterMode_ {
   Meter_Draw draw;
   const char* uiName;
   int h;
} MeterMode;

typedef enum {
   CUSTOM_METERMODE = 0,
   BAR_METERMODE,
   TEXT_METERMODE,
   GRAPH_METERMODE,
   LED_METERMODE,
   LAST_METERMODE
} MeterModeId;

typedef struct GraphData_ {
   struct timeval time;
   double values[METER_BUFFER_LEN];
} GraphData;


#ifndef MIN
#define MIN(a,b) ((a)<(b)?(a):(b))
#endif
#ifndef MAX
#define MAX(a,b) ((a)>(b)?(a):(b))
#endif

extern MeterClass Meter_class;

Meter* Meter_new(struct ProcessList_* pl, int param, MeterClass* type);

void Meter_delete(Object* cast);

void Meter_setCaption(Meter* this, const char* caption);

void Meter_setMode(Meter* this, int modeIndex);

ListItem* Meter_toListItem(Meter* this, bool moving);

/* ---------- TextMeterMode ---------- */

/* ---------- BarMeterMode ---------- */

/* ---------- GraphMeterMode ---------- */

#define PIXPERROW_UTF8 4
#define PIXPERROW_ASCII 2

/* ---------- LEDMeterMode ---------- */

extern MeterMode* Meter_modes[];

/* Blank meter */

extern int BlankMeter_attributes[];

extern MeterClass BlankMeter_class;

#endif
