<title>CLEMOps Component Dictionary</title>
# CLEMOps Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|OPS_Get_Data|100 (0x64)|| | |   
| | | |data|DataRequest||                    

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|OPS_TLM|102 (0x66)|dataTlm||
|OPS_Result|103 (0x67)|F32||

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|OPS_CMD_RECV|100 (0x64)|| | | | |
| | | |dataEv|MathOpEv|||    
|OPS_Result|101 (0x65)|| | | | |
| | | |result|F32|||    
