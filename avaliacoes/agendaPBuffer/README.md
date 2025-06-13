Type |Offset  | Size | Purpose
-------------------------------------------
int  |0       | 4    | menu option         
int  |4       | 4    | person count        
int  |8       | 4    | name size (temp)    
int  |12      | 4    | age (temp)          
int  |16      | 4    | email size (temp)   
char |20–120  | 100  | name buffer (temp)  
char |120–220 | 100  | email buffer (temp) 
void |220+    | ...  | stored people data  


## Person Structure:

Type |Offset                           |Size        | Purpose
-------------------------------------------------------------------
char |220                              | name size  | name string
int  |220 + name size                  | 4          | age
char |220 + name size + 4              | email size | email
int  |220 + name size + 4 + email size | 4          | total offset