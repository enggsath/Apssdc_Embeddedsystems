//hardware declaration

#define lcd P2
sbit Rs=P1^1;
sbit En=P1^0;
//function declaration
void lcd_init(void);
void lcd_cmd(unsigned char);
void lcd_data(unsigned char);
void lcd_string(unsigned char[]);
void lcd_delay(unsigned int);

//function defination
void lcd_init(void)
{
	lcd_cmd(0x38);//init lcd as 8-bit display;
	lcd_cmd(0x01);//clear lcd
	lcd_cmd(0x02);//return to home
	lcd_cmd(0x0c);//display on cursor off
	lcd_cmd(0x06);//increment cursor
}
void lcd_cmd(unsigned char n)
{
	lcd=n;
	Rs=0;//rs=0-->cmd_reg
	En=1;
	lcd_delay(10);
	En=0;
}

void lcd_data(unsigned char n)
{
	lcd=n;
	Rs=1;//rs=1--->data_reg
	En=1;
	lcd_delay(10);
	En=0;
}
void lcd_string(unsigned char n[])
{
	unsigned int i;
	for(i=0;n[i]!='\0';i++)
	lcd_data(n[i]);
}
void lcd_delay(unsigned int n)
{
	int i,j;
	for(i=0;i<1000;i++)
	for(j=0;j<n;j++);
}
