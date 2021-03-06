<title>MathReceiver Component Dictionary</title>
# MathReceiver Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|MR_SET_FACTOR1|0 (0x0)|Set operation multiplication factor1| | |   
| | | |val|F32|The first factor|                    
|MR_CLEAR_EVENT_THROTTLE|1 (0x1)|Clear the event throttle| | |   

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|MR_OPERATION|0 (0x0)|Ref::MathOp|The operation|
|MR_FACTOR1S|1 (0x1)|U32|The number of MR_SET_FACTOR1 commands|
|MR_FACTOR1|2 (0x2)|F32|Factor 1 value|
|MR_FACTOR2|3 (0x3)|F32|Factor 2 value|

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|MR_SET_FACTOR1|0 (0x0)|Operation factor 1| | | | |
| | | |val|F32||The factor value|    
|MR_UPDATED_FACTOR2|1 (0x1)|Updated factor 2| | | | |
| | | |val|F32||The factor value|    
|MR_OPERATION_PERFORMED|2 (0x2)|Math operation performed| | | | |
| | | |val|Ref::MathOp||The operation|    
|MR_THROTTLE_CLEARED|3 (0x3)|Event throttle cleared| | | | |
