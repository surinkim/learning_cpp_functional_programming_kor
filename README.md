
### (번역서) 모던 C++로 배우는 함수형 프로그래밍 예제 코드

![](/cover.jpg)

* 출간일: 2018년 3월 30일
* Code::Blocks, vs2017로 구분된 각 챕터별 예제 코드가 들어 있습니다.
* 책과 관련된 문의는 corecode.pe.kr 도서 페이지에 남겨 주세요.
* 도서 정보
	* [예스24](http://www.yes24.com/24/goods/59384637)
	* [알라딘](http://www.aladin.co.kr/shop/wproduct.aspx?ItemId=138158223)
	
* 정오표

	- '01장. 모던 C++와 친숙해지기', Page 35의 range_based_for_loop.cpp    
	 소스 주석 중, '*비멤버 begin(), end() 함수를 사용해서*' 부분이 잘못됐습니다.  
	 `범위 기반 for 루프를 사용해서`가 맞습니다. 예제 코드를 다시 업데이트 했습니다.  

	- '01장. 모던 C++와 친숙해지기', Page 50  
 	 1은 소수가 아니므로 람다 함수 본문의 `if (n == 0)`이 제거돼야 합니다. 예제 코드를 다시 업데이트 했습니다.  


	- '01장. 모던 C++와 친숙해지기', Page 64  
 	 본문 예제 코드에 템플릿 인수가 누락됐습니다. 아래가 맞습니다.
	 
	 ```C++
	 auto up1 = unique_ptr<int>{};
	 auto up2 = unique_ptr<int>{ nullptr };
	 auto up3 = unique_ptr<int>{ new int { 1234 } };
	 ```
	
	 ```C++
	 auto up4 = make_unique<int>(1234);
	 ```

	- '08장. 함수형 방식으로 코드 작성하기', Page 313  
 	 '기존의 멤버 함수의 접근 지시자가 private에서 public으로 변경됐고 ...' 부분이 잘못됐습니다. 아래가 맞습니다.  
	 **'기존의 멤버 함수의 접근 지시자가 public에서 private으로 변경됐고 ...'**
