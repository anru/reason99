let rec last_element_01 = (ll: list('a)) =>
  switch ll {
  | [] => None
  | [x] => Some(x)
  | [_, ...rest] => last_element_01(rest)
  };

let rec last_two_02 = (ll: list('a)) =>
  switch ll {
  | [] => None
  | [a, b] => Some((a, b))
  | [_] => None
  | [_, ...rest] => last_two_02(rest)
  };

let rec at_03 = (k: int, ll: list('a)) =>
  switch (k, ll) {
  | (0, [a, ..._]) => Some(a)
  | (k, [_, ...rest]) => at_03(k - 1, rest)
  | (_, _) => None
  };

let rec length_04 = (ll: list('a)) =>
  switch ll {
  | [] => 0
  | [_, ...rest] => length_04(rest) + 1
  };

let rev_05 = (ll: list('a)) => {
  let rec reverse = (acc: list('a), result: list('a)) =>
    switch (acc, result) {
    | ([a, ...rest], result) => reverse(rest, [a, ...result])
    | ([], result) => result
    };
  reverse(ll, [])
};