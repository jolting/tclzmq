[section {Messages}]

[subsection {Message PACKAGE COMMANDS}]

[list_begin definitions]

[call [cmd {zmq message}] [opt [arg messageName]] [opt [arg {-size <integer>}]] [opt [arg {-data <string>}]]]

This command creates a new ZeroMQ message object and associated Tcl object
command whose name is [arg messageName] if specified or auto generated if not
specified with specified size and data. The object command will be created under
the current namespace if the [arg messageName] is not fully qualified, and in the
specified namespace otherwise. The object command name is returned by this
command. The object command methods are explained in section [sectref {Message OBJECT METHODS}].

[para]
The use of this message type is not needed with the wrapper. Check the
[sectref {Socket OBJECT METHODS}] for socket commands directly reading and writing string
and [sectref {Message helper functions}] for utility functions to read and write
strings.

[list_end]

[subsection {Message OBJECT METHODS}]

[list_begin definitions]

[call [arg messageName] [method cget] [arg optionName]]

Get message option. See [cmd configure] method for list of supported options.

[call [arg messageName] [method close]]

See [cmd destroy] method.

[call [arg messageName] [method configure] [opt [arg optionName]] [opt [arg "optionValue optionName optionValue ..."]]]

Query or modify message options.  If no option is specified, returns a list
describing all of the available options. If option is specified with no value,
then the command returns the value for the specified option. If one or more
option-value pairs are specified, then the command modifies the given message
option(s) to have the given value(s); in this case the command returns an empty
string. Supported options with associated data type are:

[list_begin options]
[opt_def MORE] integer, read-only
[list_end]

[call [arg messageName] [method copy] [arg destinationMessageName]]

Copy the message to the specified message.

[call [arg messageName] [method data]]

Get the message data as a (binary) string.

[call [arg messageName] [method destroy]]

Close the ZeroMQ message and delete the associated Tcl object command.

[call [arg messageName] [method dump]]

Get the message as a human readable string.

[call [arg messageName] [method get] [arg optionName]]

Get message option. See [cmd configure] method for list of supported options.

[call [arg messageName] [method more]]

Get indication if more messages are to be received as part of a multi part
message.

[call [arg messageName] [method move] [arg destinationMessageName]]

Move contents to the specified message.

[call [arg messageName] [method recv] [arg socketName] [opt [arg flagsList]]]

Receive a message on the specified socket. Only the [term DONTWAIT] flag is supported.

[call [arg messageName] [method send] [arg socketName] [opt [arg flagsList]]]

Send a message to the specified socket as message part. Supported flags are
[term DONTWAIT] and [term SNDMORE].

[call [arg messageName] [method sendmore] [arg socketName] [opt [arg flagsList]]]

Send a message to the specified socket as message part and indicate there are
more parts to come as part of a multi part message. Supported flags are
[term DONTWAIT] and [term SNDMORE].

[call [arg messageName] [method set] [arg optionName] [arg optionValue]]

Set message option. See [cmd configure] method for list of supported options.

[call [arg messageName] [method size]]

Return the size of the message data part.

[list_end]
