#include <avr/io.h>
#define F_CPU 1600000UL
#define bit_is_set(sfr, bit) (_SFR_BYTE(sfr) & _BV(bit)) // 특정비트가 1로 설정되었는지 검사하는 함수
#define bit_is_clear(sfr, bit) (!(_SFR_BYTE(sfr) & _BV(bit))) // 특정비트가 0으로 설정되었는지 검사하는 함수
#include <util/delay.h>

void INIT_PORT(void)
{
  DDRB = 0x20; // PB5(디지털 13번 핀) 출력으로 설정
  PORTB = 0x00; // LED는 꺼진 상태에서 시작

  DDRD = 0x00; // 버튼입력
  PORTD = 0x04; // PD2(디지털 2번 핀) 풀업 저항 사용
}

int main(void)
{
  INIT_PORT();  //포트설정
  while(1)
  {
    if(PIND & 0x04) PORTB = 0x00; //LED 끄기 (AND비트 연산자로 확인)
    else            PORTB = 0x20; //LED 켜기
  }
}
