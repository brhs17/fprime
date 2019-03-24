<title>CLEMOPs Component Dictionary</title>
# CLEMOPs Component Dictionary


## Command List

|Mnemonic|ID|Description|Arg Name|Arg Type|Comment
|---|---|---|---|---|---|
|Ops_Get_Data|100 (0x64)|| | |   
| | | |data|options||                    

## Telemetry Channel List

|Channel Name|ID|Type|Description|
|---|---|---|---|
|Ops_Type|102 (0x66)|dataTlm||
|Ops_Result|103 (0x67)|F32||

## Event List

|Event Name|ID|Description|Arg Name|Arg Type|Arg Size|Description
|---|---|---|---|---|---|---|
|Ops_CMD_RECV|100 (0x64)|| | | | |
| | | |dataEv|MathOpEv|||    
|Ops_Result|101 (0x65)|| | | | |
| | | |result|F32|||    
