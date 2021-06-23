//function declaration
void uart_init(void);
void uart_data(unsigned char);
void uart_string(unsigned char[]);
void uart_enter(void);
char uart_rx(void);
void uart_num(unsigned int);

//functions declaration

void uart_init(void)
{
	TMOD=0X20; //timer 1 mode 2
	SCON=0X50; //mode 1
	TH1=0xFD; //baurd rate 9600
	TR1=1; //start timer
}
void uart_data(unsigned char n)
{
	SBUF=n;
	while(TI==0);
	TI=0;
}
void uart_string(unsigned char n[])
{
	unsigned int i;
	for(i=0;n[i]!='\0';i++)
	uart_data(n[i]);
}
void uart_enter(void)
{
	uart_data(13);  // /n and /r
	uart_data(10); //new line
}
char uart_rx(void)
{
	char ch;
	while(RI==0);
	ch=SBUF;
	RI=0;
	return(ch);
}
void uart_num(unsigned int n)
{
	unsigned int a,b,c;
	c=n%10;
	b=n%10;
	a=n/10;
  /*
	uart_data(a+48);  //48 is ascii number of 0 ..conerting a value inot its ascii
	uart_data(b+48);
	uart_data(c+48);
	*/
	uart_data(n+48);
}
