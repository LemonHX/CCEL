//actor need to have at least four function
// recive [Type]
// send [Type]
// reply [Type_O]

//send from Type to ActorType

//hot swapping using something like functor or lambda to save value of function ptr
// become load dynamic lib to lambda
// unbecome atomaticlly yield the threadid free the old function and replace it

//so there must have one actor free
// and one actor allocator

//scheduler is needed

//scheduler needs a hash or something like hask(such as redblack tree...)
//also need to set the level of excuting code
// after consider i think just use a pointer or a list is enough cuz there is no big job

