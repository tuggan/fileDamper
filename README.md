fileDamper
==========

Yeah, still in development?

Ports used
==========
* 37300 TCP and UDP

# Packages
Numbers are written in decimal (for now).
All variables are unsigned.

## TCP

> Type code

> 0 Deny

> 10 Acknowledge

> 20 checksum

> 30 Mode


### TCP Deny

> INT Type [0]


### TCP Ack

> INT [10]


### TCP Mode

> INT Type [30]

> INT Mode


### TCP Checksum

> INT Type

> LONG Index

> LONG Checksum


## UDP

> Type code

> 0 Deny

> 10 Acknowledge

> 20 File Part


### UDP File Part

> INT Type

> LONG Part size

> CHAR[] File Part

