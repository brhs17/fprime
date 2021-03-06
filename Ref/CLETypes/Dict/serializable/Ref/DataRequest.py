'''
Created on Wednesday, 27 March 2019
@author: bhs

THIS FILE IS AUTOMATICALLY GENERATED - DO NOT EDIT!!!

XML Source: CLERequestSerializableAi.xml
'''


# Import the types this way so they do not need prefixing for execution.
from models.serialize.type_exceptions import *
from models.serialize.type_base import *

from models.serialize.bool_type import *
from models.serialize.enum_type import *
from models.serialize.f32_type import *
from models.serialize.f64_type import *

from models.serialize.u8_type import *
from models.serialize.u16_type import *
from models.serialize.u32_type import *
from models.serialize.u64_type import *

from models.serialize.i8_type import *
from models.serialize.i16_type import *
from models.serialize.i32_type import *
from models.serialize.i64_type import *

from models.serialize.string_type import *
from models.serialize.serializable_type import *


class DataRequest(SerializableType):


    def __init__(self):
    
        m_list = [
            ("target",EnumType("type",{"GyroXSer":0,"GyroYSer":1,"GyroZSer":2,"RTCTimeSer":3,}),"%s"),
            ("result",F32Type(),"%g"),
        ]
        
        super(DataRequest,self).__init__("DataRequest",m_list)
                    

