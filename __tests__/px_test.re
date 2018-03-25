open Jest;

describe(
  "99 problems",
  () => {
    open Expect;
    test("p01_1", () => expect(Pr.last_element_01([12, 21, 47])) |> toEqual(Some(47)));
    test("p01_2", () => expect(Pr.last_element_01([])) |> toBe(None));
    test("p02_1", () => expect(Pr.last_two_02([12, 21, 47])) |> toEqual(Some((21, 47))));
    test("p02_2", () => expect(Pr.last_two_02(["12", "21", "47"])) |> toEqual(Some(("21", "47"))));
    test("p02_3", () => expect(Pr.last_two_02([12])) |> toBe(None));
    test("p03_1", () => expect(Pr.at_03(1, [12, 21, 47])) |> toEqual(Some(21)));
    test("p03_2", () => expect(Pr.at_03(2, [12, 21, 47])) |> toEqual(Some(47)));
    test("p03_2", () => expect(Pr.at_03(6, [12, 21, 47])) |> toEqual(None));
    test("p04_1", () => expect(Pr.length_04([12, 21, 47])) |> toEqual(3));
    test("p04_1", () => expect(Pr.length_04([])) |> toEqual(0));
    test("p05_1", () => expect(Pr.rev_05([12, 21, 47])) |> toEqual([47, 21, 12]));
    test("p05_2", () => expect(Pr.rev_05([])) |> toEqual([]));
    test("p06_1", () => expect(Pr.is_palindrome([1, 2, 3, 2, 1])) |> toBe(true));
    test("p06_1", () => expect(Pr.is_palindrome([1, 2, 2, 1])) |> toBe(true));
    test("p06_1", () => expect(Pr.is_palindrome([1, 2, 2, 2])) |> toBe(false))
  }
);