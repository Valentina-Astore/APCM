rm Java2CClient
rm Java2CServer
rm C2JavaClient
rm C2JavaServer

mkfifo Java2CEClient
mkfifo Java2CEServer
mkfifo C2JavaEClient
mkfifo C2JavaEServer

mkfifo Java2CDClient
mkfifo Java2CDServer
mkfifo C2JavaDClient
mkfifo C2JavaDServer

./AES_CFB_E Client
./AES_CFB_E Server
./AES_CFB_D Client
./AES_CFB_D Server
java Server
java Client

