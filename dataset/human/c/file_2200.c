#include <stdio.h>

int main(void)
{
    char c_inputCharacterBuffer, c_decoy;
    char inputString[200001] = {'\0'}, addForward[200001] = {'\0'}, addBackward[200001] = {'\0'};
    int operateFlag, reverseFlag = 0, addFlag;
    int operateCount, stringCount = 0, addForwardCount = 0, addBackwardCount = 0;
    scanf("%s", inputString);
    for (int index = 0; inputString[index] != '\0'; index++)
    {
        stringCount++;
    }
    scanf("%d", &operateCount);

    for (int index = 0; index < operateCount; index++)
    {
        scanf("%d", &operateFlag);
        if (operateFlag == 1)
        {
            if (reverseFlag == 0)
            {
                reverseFlag = 1;
            }
            else if (reverseFlag == 1)
            {
                reverseFlag = 0;
            }
        }
        else if (operateFlag == 2)
        {
            scanf("%d%c%c", &addFlag, &c_decoy, &c_inputCharacterBuffer);
            if (reverseFlag == 0)
            {
                if (addFlag == 1)
                {
                    addForward[addForwardCount] = c_inputCharacterBuffer;
                    addForwardCount++;
                }
                else if (addFlag == 2)
                {
                    addBackward[addBackwardCount] = c_inputCharacterBuffer;
                    addBackwardCount++;
                }
            }
            else if (reverseFlag == 1)
            {
                if (addFlag == 1)
                {
                    addBackward[addBackwardCount] = c_inputCharacterBuffer;
                    addBackwardCount++;
                }
                else if (addFlag == 2)
                {
                    addForward[addForwardCount] = c_inputCharacterBuffer;
                    addForwardCount++;
                }
            }
        }
    }

    if (reverseFlag == 0)
    {
        if (addForwardCount > 0)
        {
            for (int index = addForwardCount - 1; index >= 0; index--)
            {
                printf("%c", addForward[index]);
            }
        }
        printf("%s", inputString);
        printf("%s", addBackward);
    }
    else if (reverseFlag == 1)
    {
        if (addBackwardCount > 0)
        {
            for (int index = addBackwardCount - 1; index >= 0; index--)
            {
                printf("%c", addBackward[index]);
            }
        }
        for (int index = stringCount - 1; index >= 0; index--)
        {
            printf("%c", inputString[index]);
        }
        printf("%s", addForward);
    }

    return 0;
}
