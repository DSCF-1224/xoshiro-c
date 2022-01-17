int fprintf_state_size ( FILE *const stream , const Generator *const generator )
{
	return fprintf( stream , "%s %ld%s\n" , "The number of state is" , state_size(generator) , "." );
}
