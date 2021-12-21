

use std::fs::File;
use std::io::{self, BufRead};
use std::process;

fn main() {

	let mut vec_o2: Vec<String> = Vec::new();
	let mut vec_co2: Vec<String> = Vec::new();

	let file = match File::open("input"){
		Ok(a) => a,
		Err(a) => {
			println!("ERR: {}", a);
			process::exit(1);
		},
	};

	let lines = io::BufReader::new(file).lines();

	for line_r in lines {
		if let Ok(line) = line_r {
			vec_o2.push(line.clone());
			vec_co2.push(line);
		}
	}

	let esize: usize = vec_o2[0].chars().count();

	//o2

	for i in 0..esize{

		let (count_1, total) = count_n_1(&vec_o2, i);
		
		let o2_keep_1: bool = count_1 as f32 >= (total as f32)/2.0;

		vec_o2.retain(|x| (o2_keep_1 && x.chars().nth(i).unwrap()=='1') ||
			(!o2_keep_1 && x.chars().nth(i).unwrap()=='0') );

		if vec_o2.len() == 1 {
			break;
		}
	}

	let o2_num=cvt_bin_str_to_i32(&vec_o2[0]);

	//co2
	for i in 0..esize{

		let (count_1, total) = count_n_1(&vec_co2, i);
		
		let co2_keep_0: bool = (count_1 as f32) >= (total as f32)/2.0;

		vec_co2.retain(|x| (co2_keep_0 && x.chars().nth(i).unwrap()=='0') ||
			(!co2_keep_0 && x.chars().nth(i).unwrap()=='1') );

		if vec_co2.len() == 1 {
			break;
		}
	}

	let co2_num=cvt_bin_str_to_i32(&vec_co2[0]);

	println!("o2:{} co2:{} RES: {}", o2_num, co2_num, o2_num*co2_num);

}

fn cvt_bin_str_to_i32(s: &String) -> u32 {
	let mut res: u32 = 0;
	let mut i: i16 = 0;
	for c in s.chars().rev() {
		res |= c.to_digit(10).unwrap()<<i;
		i+=1;
	}
	return res;
}

fn count_n_1(v: &Vec<String>, ch_idx: usize) -> (i32,i32) {
	let mut total: i32 = 0;
	let mut count_1: i32 =0;	
	
	for num in v {
		if num.chars().nth(ch_idx).unwrap() == '1' {
			count_1 += 1;
		}
		total += 1;
	}
	
	return (count_1,total);
}
