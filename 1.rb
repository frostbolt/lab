def f(x)
 	#return 2*x + Math.atan(x)
 	x
end 

1000.times do |x|
	if (f(-x/100) != -f(x/100))
		puts "НЕТ!"
	end
end

