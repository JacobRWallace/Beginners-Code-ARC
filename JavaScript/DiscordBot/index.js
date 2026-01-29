const {token} = require('./config.json');
const {Client, Events, GatewayIntentBits, SlashCommandBuilder} = require('discord.js');

const client = new Client({intents: [GatewayIntentBits.Guilds] });

client.once(Events.ClientReady, c => {
    console.log(`Logged in as ${c.user.tag}`);

    new SlashCommandBuilder()
        .setName('ping')
        .setDescription('Replies with Pong!');

    const pingCommand = ping.toJSON();
    client.commands.create(pingCommand, "1283886497950339216");
});

client.on(Events.InteractionCreate, interaction => {
    if(interaction.isChatInputCommand()) return;
    console.log(interaction);
});

client.login(token);