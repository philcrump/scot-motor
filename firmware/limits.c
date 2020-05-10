#include "main.h"

void limits_get_limits(bool *limit_1, bool *limit_2)
{
    *limit_1 = palReadLine(LINE_LIMIT_1);
    *limit_2 = palReadLine(LINE_LIMIT_2);
}

bool limits_get_limit_1(void)
{
    return palReadLine(LINE_LIMIT_1);
}

bool limits_get_limit_2(void)
{
    return palReadLine(LINE_LIMIT_2);
}