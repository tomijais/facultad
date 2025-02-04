----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/04/2025 03:46:02 PM
-- Design Name: 
-- Module Name: Lab0A_tb - bench
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

entity Lab0A_tb is
--  Port ( );
end Lab0A_tb;

architecture bench of Lab0A_tb is

component Lab0A is
    Port ( A,B : in STD_LOGIC;
           F_NOT,F_AND,F_OR : out STD_LOGIC);
end component;

signal A_tb, B_tb : std_logic;
signal F_NOT_tb, F_AND_tb, F_OR_tb : std_logic;

begin


uut: Lab0A port map (A => A_tb,
    B => B_tb,
    F_NOT => F_NOT_tb,
    F_AND => F_AND_tb,
    F_OR => F_OR_tb);
    

stimulus: process
    begin
    A_tb <= '0'; B_tb <= '0'; wait for 100 ns;
    A_tb <= '0'; B_tb <= '1'; wait for 100 ns;
    A_tb <= '1'; B_tb <= '1'; wait for 100 ns;
    A_tb <= '1'; B_tb <= '0'; wait for 100 ns;
    wait;
end process;

end bench;
