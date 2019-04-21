<title>CLEAgg Component Dictionary</title>
# CLEAgg Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|CLEAgg_SET_GYROX|100 (0x64)|| | |   
| | | |val|F32||                    
|CLEAgg_SET_GYROY|101 (0x65)|| | |   
| | | |val|F32||                    
|CLEAgg_SET_GYROZ|102 (0x66)|| | |   
| | | |val|F32||                    
|CLEAgg_SET_RTC_TIME|103 (0x67)|| | |   
| | | |val|F32||                    
|CLEAgg_CLEAR_EVENT_THROTTLE|104 (0x68)|| | |   

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|CLEAgg_DATA_REQUEST|100 (0x64)|Ref::DataRequest||
|CLEAgg_GYROXS|101 (0x65)|U32||
|CLEAgg_GYROYS|102 (0x66)|U32||
|CLEAgg_GYROZS|103 (0x67)|U32||
|CLEAgg_RTC_TIMES|104 (0x68)|U32||
|CLEAgg_GYROX|105 (0x69)|F32||
|CLEAgg_GYROY|106 (0x6a)|F32||
|CLEAgg_GYROZ|107 (0x6b)|F32||
|CLEAgg_RTC_TIME|108 (0x6c)|F32||

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|CLEAgg_SET_GYROX|100 (0x64)|| | | | |
| | | |val|F32|||    
|CLEAgg_SET_GYROY|101 (0x65)|| | | | |
| | | |val|F32|||    
|CLEAgg_SET_GYROZ|102 (0x66)|| | | | |
| | | |val|F32|||    
|CLEAgg_SET_RTC_TIME|103 (0x67)|| | | | |
| | | |val|F32|||    
|CLEAgg_REQUEST_COMPLETED|104 (0x68)|| | | | |
| | | |val|Ref::DataRequest|||    
|CLEAgg_THROTTLE_CLEARED|105 (0x69)|| | | | |
