#define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>
#include "UART.h" //UART 라이브러리 사용

void INIT_PORT(void)
{
  DDRB = 0x20; //PB5(디지털 13번 핀) 출력으로 설정
  PORTB = 0x00; //LED는 꺼진 상태에서 시작

  DDRD = 0x00;
  PORTD = 0x04; //PD2(디지털 2번 핀) 풀업 저항 사용
}

int main(void)
{
  UART_INIT();
  INIT_PORT();
  ini state = 0;

  while(1){
    if(PIND & 0x04){
      state = 0; //버튼이 눌러지지 않은 상태로 표시
      PORTB = 0x00; //LED끄기
    }
    else{
        //눌러지지 않은 상태에서 눌러진 상태로 바뀔 때마다. '*'전송
        if(state == 0) UART_transmit('*');
        state = 1;  //버튼이 눌러진 상태로 표시
        PORTB = 0x20; //LED켜기
        _delay_ms(100) //디바운싱 
    }
  }
}
