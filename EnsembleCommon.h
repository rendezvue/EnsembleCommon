#ifndef _RENDEZVUE_COMMON_H_
#define _RENDEZVUE_COMMON_H_

#include "opencv2/opencv.hpp"

#include <sys/time.h>
#include <list>
static inline long myclock()
{
	struct timeval tv;
	gettimeofday (&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

#define DB_PATH "./ENSEMBLE_DB"
#define DB_PATH_PREFIX_PROJECT		"ensemble_project_"
#define DB_PATH_PREFIX_JOB			"ensemble_job_"
#define DB_PATH_PREFIX_TOOL			"ensemble_tool_"
#define DB_PATH_PREFIX_OPTION		"ensemble_option_"

#define INTERFACE
#define IN
#define OUT
#define INOUT


#define RAD_TO_DEG		(180.0/CV_PI)
#define DEG_TO_RAD		(CV_PI/180.0)
#define TWO_PI			(CV_PI*2.0)

#define IMAGE_WIDTH_VIA_ETH			640
#define IMAGE_HEIGHT_VIA_ETH		480

#define NETWORK_PORT_CON 4000		//Control Network Port

enum JobType
{	
	JOB_TYPE_UNKNOWN			= 10000,
	JOB_TYPE_PROJECT			= 20000 ,
	JOB_TYPE_BASE				= 30000 ,
	JOB_TYPE_TOOL				= 40000,
	JOB_TYPE_TOOL_OPTION		= 50000,
	JOB_TYPE_CANDIDATE			= 60000
};

enum BaseTypeList
{	
	BASE_TYPE_UNKNOWN			= JOB_TYPE_BASE,
	BASE_TYPE_DETECT_OBJECT,
	BASE_TYPE_DETECT_BEST_OBJECT ,
	BASE_TYPE_ROBOT_MISSION ,	
};
	

#define TOOL_TYPE_BASE_VALUE	100
enum ToolTypeList
{	
	TOOL_TYPE_UNKNOWN			= JOB_TYPE_TOOL,
	TOOL_TYPE_DETECT_OBJECT		= TOOL_TYPE_UNKNOWN 		+ TOOL_TYPE_BASE_VALUE,
	TOOL_TYPE_DETECT_LINE		= TOOL_TYPE_DETECT_OBJECT 	+ TOOL_TYPE_BASE_VALUE,
	TOOL_TYPE_DETECT_CIRCLE		= TOOL_TYPE_DETECT_LINE 	+ TOOL_TYPE_BASE_VALUE,
	TOOL_TYPE_DETECT_CODE		= TOOL_TYPE_DETECT_CIRCLE	+ TOOL_TYPE_BASE_VALUE,
	TOOL_TYPE_CALC_DISTANCE		= TOOL_TYPE_DETECT_CODE 	+ TOOL_TYPE_BASE_VALUE,
	TOOL_TYPE_CALC_ANGLE		= TOOL_TYPE_CALC_DISTANCE 	+ TOOL_TYPE_BASE_VALUE,
	TOOL_TYPE_OFFSET_DISTANCE	= TOOL_TYPE_CALC_ANGLE 		+ TOOL_TYPE_BASE_VALUE,

	//Option
	TOOL_TYPE_OPTION_INSPECT_CRACK 	= TOOL_TYPE_DETECT_OBJECT + 1,
	TOOL_TYPE_OPTION_INSPECT_COLOR,
	TOOL_TYPE_OPTION_INSPECT_DIAMETER	= TOOL_TYPE_DETECT_CIRCLE +1,
	TOOL_TYPE_OPTION_INSPECT_DISTANCE 	= TOOL_TYPE_CALC_DISTANCE + 1,
	TOOL_TYPE_OPTION_INSPECT_ANGLE 	= TOOL_TYPE_CALC_ANGLE + 1,
};

typedef struct _Source
{
	cv::Mat input;
	cv::Mat gray;
	cv::Mat vga ;
} Source;

enum DrawOption
{
	DRAW_OPTION_COLOR	= 0x01,
	DRAW_OPTION_FEATURE = 0x02,
	DRAW_OPTION_OUTLINE = 0x04,
	DRAW_OPTION_CENTER = 0x08,
	DRAW_OPTION_RECT = 0x10,
	DRAW_OPTION_DOMINANT = 0x20,
	DRAW_OPTION_DARK = 0x40,
	DRAW_OPTION_ZOOM = 0x80,
	DRAW_OPTION_TEXT = 0x81,
	DRAW_OPTION_ALL = 0xFF
};

enum DrawResultOption
{
	RESULT_DRAW_OPTION_SEARCH_FEAT	= 0x0001,
	RESULT_DRAW_OPTION_SEARCH_BOX	= 0x0002,
	RESULT_DRAW_OPTION_SEARCH_ARROW	= 0x0004,
	RESULT_DRAW_OPTION_MASTER_FEAT	= 0x0008,
	RESULT_DRAW_OPTION_MASTER_BOX	= 0x0010,
	RESULT_DRAW_OPTION_MASTER_TEXT	= 0x0020,
	RESULT_DRAW_OPTION_OBJECT		= 0x0040,
	RESULT_DRAW_OPTION_OBJECT_TEXT	= 0x0080,
	WITH_DRAW_OPTION_FEATURE		= 0x0100,
	WITH_DRAW_SEARCH_AREA_RANGE		= 0x0200,
	RESULT_DRAW_OPTION_ALL = 0xFFFF

};

enum DetectOption
{
	DETECT_OPTION_MARGIN ,
	DETECT_OPTION_THRESHOLD,
	DETECT_OPTION_COUNT,
	DETECT_OPTION_CALC_DISTANCE ,
	DETECT_OPTION_BASE_DISTANCE,	
	DETECT_OPTION_CALC_ANGLE ,
	DETECT_OPTION_CONSTRAINT_ANGLE_MIN,
	DETECT_OPTION_CONSTRAINT_ANGLE_MAX,
};

enum GetImageOption
{
	GET_IMAGE_INPUT = 201,
	GET_IMAGE_DEVICE_ICON,
	GET_IMAGE_BASE,
	GET_IMAGE_BASE_WITH_INFO,
	GET_IMAGE_BASE_ROI,
	GET_IMAGE_CALIBRATION_FEATURE,
	GET_IMAGE_BASE_HISTORY_MASK,
	GET_IMAGE_BASE_TEMP
};

enum ImageTypeOption
{
    IMAGE_RGB888		= 0x00000001,
	IMAGE_YUV420 		= 0x00000002
};

enum ImageExtOption
{
	IMAGE_ADD_TIME 			= 0x00000100,
	IMAGE_ADD_COUNT 		= 0x00000200,
	IMAGE_ADD_SOURCE_INFO 	= 0x00000400,
	IMAGE_THUMBNAIL 		= 0x00008000,
	IMAGE_ALL_AREA 			= 0x00004000,
	IMAGE_ICON				= 0x00002000,
};

enum HistogramUseOption
{
	HISTOGRAM_USE_GRAY = 0x0001,
	HISTOGRAM_USE_RED = 0x0002,
	HISTOGRAM_USE_GREEN = 0x0004,
	HISTOGRAM_USE_BLUE = 0x0008,
	HISTOGRAM_USE_ALL = 0xFFFF
};


#endif
