let rec last_element_01 = (ll: list('a)) =>
  switch ll {
  | [] => None
  | [x] => Some(x)
  | [_, ...rest] => last_element_01(rest)
  };

let rec last_two_02 = (ll: list('a)) : option(('a, 'a)) =>
  switch ll {
  | [] => None
  | [a, b] => Some((a, b))
  | [_] => None
  | [_, ...rest] => last_two_02(rest)
  };