#ifndef ErrorCode_H
#define ErrorCode_H

typedef enum{
	ERR_NO_ERROR,
	ERR_NUMBER_NOT_WELL_FORMED
} ErrorCode;

typedef enum{
	NO_ERROR,
	ILLEGAL_DESTINATION,
	EMPTY_ARGUMENT
} ErrorInterpret;

#endif //ErrorCode_H