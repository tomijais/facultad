----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/04/2025 02:19:34 PM
-- Design Name: 
-- Module Name: AND_3_tb - bench
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity AND_3_tb is
--  Port ( );
end AND_3_tb;

architecture bench of AND_3_tb is

component AND_3 -- Declare the component we'll be testing
    Port (A,B,C : in STD_LOGIC;
        F : out STD_LOGIC);
end component;

signal A_tb, B_tb, C_tb : STD_LOGIC; -- Declare our internal test bench
signal F_tb : STD_LOGIC; -- signals


begin

uut: AND_3 port map (A => A_tb, -- Map out AND_3 input/output
    B => B_tb, -- pints to out internal test bench
    C => C_tb, -- signals. The AND_3 source is our
    F => F_tb ); -- "unit under test" (UUT).

stimulus : process -- The process black will execute each line sequentially
begin -- Apply out test values, waiting for 100 ns before moving on
    A_tb <= '0'; B_tb <= '0'; C_tb <= '1'; wait for 100 ns;
    A_tb <= '0'; B_tb <= '1'; C_tb <= '0'; wait for 100 ns;
    A_tb <= '0'; B_tb <= '1'; C_tb <= '1'; wait for 100 ns;
    A_tb <= '1'; B_tb <= '0'; C_tb <= '0'; wait for 100 ns;
    A_tb <= '1'; B_tb <= '0'; C_tb <= '1'; wait for 100 ns;
    A_tb <= '1'; B_tb <= '1'; C_tb <= '0'; wait for 100 ns;
    A_tb <= '1'; B_tb <= '1'; C_tb <= '1'; wait for 100 ns;
    A_tb <= '0'; B_tb <= '0'; C_tb <= '0'; wait for 100 ns;
wait;

end process;
end bench;
